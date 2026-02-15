//
// Created by Anna Goerth on 15.02.26.
//

#ifndef SATSUMA_UTILITY_H
#define SATSUMA_UTILITY_H

/**
* \brief Rudimentary class to keep track of time.
*/
class stopwatch {
    std::chrono::high_resolution_clock::time_point time_pt;
public:
    /**
    * Start the timer.
    */
    void start() {
        time_pt = std::chrono::high_resolution_clock::now();
    }

    /**
    * Retrieves the time elapsed since the start of the timer.
    */
    double stop() {
        const std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
        return (std::chrono::duration_cast<std::chrono::nanoseconds>(now - time_pt).count()) / 1000000.0;
    }
};

/**
 * \brief Prints information to the console.
 *
 * Contains additional facilities to measure elapsed time in-between prints.
 */
class profiler {
    std::vector<std::pair<std::string, double>> results;
public:
    void add_result(std::string name, double result) {
        results.push_back({name, result});
    }
    void print_results(std::ostream& print_to, const double independent_total = -1) {

        double total = 0;
        for (auto const &[name, time]: results) {
            total += time;
        }
        if(independent_total > 0 && independent_total > total) {
            const double t_other = independent_total - total;
            add_result("other", t_other);
            total = independent_total;
        }

        if(total == 0) total += 0.001;

        std::sort(results.begin(), results.end(), [](auto &left, auto &right) {
            return left.second > right.second;
        });

        print_to<< std::setprecision(2) << std::fixed;
        for(auto const& [name, time] : results) {
            print_to << "c " << std::right << std::setw(22) << time << "ms" << std::right << std::setw(6) << (time/total)*100 << std::setw(1) << "%"  << std::left << " " << name <<  "\n";
        }
        print_to << "c         ───────────────────────────────────────────────\n";
        print_to << "c " << std::right << std::setw(22) << total << "ms" << std::right << std::setw(6) << 100 << std::setw(1) << "%"  << std::left << " " << "total" <<  "\n";


    }
};

static void terminate_with_error(std::string error_msg) {
    std::cerr << "c \nc " << error_msg << std::endl;
    exit(1);
}


#endif //SATSUMA_UTILITY_H