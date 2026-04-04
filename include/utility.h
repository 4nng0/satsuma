//
// Created by Anna Goerth on 15.02.26.
//

#include <cassert>
#include <iostream>
#include <algorithm>
#include <random>
#include <cstring>
#include <chrono>
#include <iomanip>
#include <fstream>

#ifndef SATSUMA_UTILITY_H
#define SATSUMA_UTILITY_H

#define SATSUMA_VERSION_MAJOR 1
#define SATSUMA_VERSION_MINOR 2
#define DEJAVU_VERSION_MAJOR 2
#define DEJAVU_VERSION_MINOR 1
#define DEJAVU_VERSION_IS_PREVIEW false

#if defined (__unix__) || (defined (__APPLE__) && defined (__MACH__))
#define satsuma_getc(f) getc_unlocked(f)
#define satsuma_putc(f, c) putc_unlocked(f, c)
#define satsuma_flockfile(f) flockfile(f);
#define satsuma_funlockfile(f) funlockfile(f);
#else
#define satsuma_getc(f) getc(f)
#define satsuma_putc(f, c) putc(f, c)
#define satsuma_flockfile(f) {};
#define satsuma_funlockfile(f) {};
#endif


static inline bool this_file_exists(const std::string& name) {
    std::ifstream f(name.c_str());
    return f.good();
}


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

inline void terminate_with_error(std::string error_msg) {
    std::cerr << "c \nc " << error_msg << std::endl;
    exit(1);
}


#endif //SATSUMA_UTILITY_H