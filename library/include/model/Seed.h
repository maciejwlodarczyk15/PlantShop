#ifndef ROSLINY_SEED_H
#define ROSLINY_SEED_H

#include "Product.h"

class Seed : public Product{
private:
    float weight;
public:
    Seed(int id, const std::string &name, float price, float weight);

    std::string productInfo() override;

    float getTotalPrice() override;

    float getWeight() const;
};


#endif //ROSLINY_SEED_H
