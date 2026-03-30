//
// Created by Anna Goerth on 14.02.26.
//

#ifndef SATSUMA_IPREPROCESSOR_H
#define SATSUMA_IPREPROCESSOR_H

#pragma once
#include <string>
#include <memory>
#include <vector>
#include "ICnf2wl.h"
#include "utility.h"

class profiler;

namespace satsuma {
    class ISatsumaPreprocessor {
    public:
        virtual ~ISatsumaPreprocessor() = default;

        virtual void output_file(std::string& outfile) = 0;
        virtual void preprocess(ICnf2wl& formula) = 0;

        // Setter
        virtual void set_break_depth(int depth) = 0;
        virtual void set_row_orbit_limit(int limit) = 0;
        virtual void set_row_column_orbit_limit(int limit) = 0;
        virtual void set_johnson_orbit_limit(int limit) = 0;
        virtual void set_opt_passes(int passes) = 0;
        virtual void set_opt_conjugations(int conjugations) = 0;
        virtual void set_opt_random(int random) = 0;
        virtual void set_opt_reopt(bool reopt) = 0;
        virtual void set_dejavu_print(bool print) = 0;
        virtual void set_dejavu_prefer_dfs(bool prefer_dfs) = 0;
        virtual void set_optimize_generators(bool optimize) = 0;
        virtual void set_dejavu_backtrack_limit(int limit) = 0;
        virtual void set_component_size_limit(int limit) = 0;
        virtual void set_absolute_support_limit(int limit) = 0;
        virtual void set_split_limit(int limit) = 0;
        virtual void set_preprocess_cnf(bool enable) = 0;
        virtual void set_preprocess_cnf_subsume(bool enable) = 0;
        virtual void set_hypergraph_macros(bool enable) = 0;
        virtual void set_binary_clauses(bool enable) = 0;
        virtual void set_struct_only(bool enable) = 0;
        virtual void set_graph_only(bool enable) = 0;
		virtual void set_log_output(std::ostream* new_logout) = 0;

    	virtual std::vector<int>&& extractPreprocessedFormula() = 0 ;
    	virtual bool hasPreprocessedFormula() = 0;
    	virtual void set_save_as_Formula(bool save) = 0;
    	virtual int get_number_of_new_clauses() = 0;

		virtual int  get_row_column_orbit_limit() const = 0;
		virtual int get_row_orbit_limit() const  = 0;
		virtual int get_johnson_orbit_limit() const = 0;
		virtual int get_break_depth() const = 0;

        virtual void set_profiler(profiler* p) = 0;
        virtual void enable_proof_logging(const std::string& filename) = 0;
    };

    // Factory für den Preprocessor
    extern std::unique_ptr<ISatsumaPreprocessor> create_preprocessor();
}

#endif //SATSUMA_IPREPROCESSOR_H