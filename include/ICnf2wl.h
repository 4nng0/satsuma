//
// Created by Anna Goerth on 14.02.26.
//

#ifndef SATSUMA_ICNF2WL_H
#define SATSUMA_ICNF2WL_H


#pragma once
#include <vector>
#include <memory>

// Das abstrakte Interface
namespace satsuma {
class ICnf2wl{
public:
    virtual ~ICnf2wl() = default;

    // Deine gewünschten öffentlichen Methoden
    virtual void reserve(int n, int m) = 0;
    virtual void add_clause(std::vector<int>& clause) = 0;

    // Eventuell nützliche Getter, die du oben hattest:
    virtual int n_variables() = 0;
    virtual bool is_conflicting() = 0;

    virtual int n_redundant_clauses() = 0;
    virtual int n_len() = 0;
    virtual int n_clauses() = 0;
};

// Die Factory-Funktion, um eine Instanz der Implementierung zu erhalten
extern  std::unique_ptr<ICnf2wl> create_cnf2wl();
}

#endif //SATSUMA_ICNF2WL_H