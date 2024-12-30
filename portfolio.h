#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include <vector>
#include <string>
#include <algorithm>

class Investment {
public:
    std::string name;
    double value;
    std::string type;

    Investment(const std::string& name, double value, const std::string& type)
        : name(name), value(value), type(type) {}
};

class Portfolio {
private:
    std::vector<Investment> investments;

public:
    void addInvestment(const std::string& name, double value, const std::string& type) {
        investments.push_back(Investment(name, value, type));
    }

    void removeInvestment(const std::string& name) {
        investments.erase(std::remove_if(investments.begin(), investments.end(),
                                         [&](const Investment& inv) { return inv.name == name; }),
                          investments.end());
    }

    void optimize() {
        // Implémente l'algorithme d'optimisation ici
    }

    std::vector<Investment> getInvestments() const {
        return investments;
    }
};

#endif // PORTFOLIO_H
