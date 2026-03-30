//
// Created by Anna Goerth on 15.02.26.
//

#include "include/ICnf2wl.h"
#include "include/ISatsumaPreprocessor.h"
#include "cnf2wl.h"       // Deine interne Implementierung
#include "preprocessor.h" // Deine interne Implementierung
#include <memory>

namespace satsuma {
    // Hier wird der Maschinencode für die Symbole generiert,
    // die der Linker gerade vermisst:
    std::unique_ptr<ICnf2wl> create_cnf2wl() {
        return std::make_unique<cnf2wl>();
    }

    std::unique_ptr<ISatsumaPreprocessor> create_preprocessor() {
        return std::make_unique<preprocessor>();
    }
}