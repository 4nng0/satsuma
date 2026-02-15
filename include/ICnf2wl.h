//
// Created by Anna Goerth on 14.02.26.
//

#ifndef SATSUMA_ICNF2WL_H
#define SATSUMA_ICNF2WL_H


#pragma once
#include <vector>
#include <memory>

// Das abstrakte Interface
class ICnf2wl{
public:
    virtual ~ICnfProcessor() = default;

    // Deine gewünschten öffentlichen Methoden
    virtual void reserve(int n, int m) = 0;
    virtual void add_clause(std::vector<int>& clause) = 0;

    // Eventuell nützliche Getter, die du oben hattest:
    virtual int n_variables() = 0;
    virtual bool is_conflicting() = 0;

    n_redundant_clauses()
    n_len()
    n_clauses()
};

// Die Factory-Funktion, um eine Instanz der Implementierung zu erhalten
extern "C" std::unique_ptr<ICnfProcessor> create_cnf2wl();


#endif //SATSUMA_ICNF2WL_H