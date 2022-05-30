#ifndef ROSLINY_SEEDLE_H
#define ROSLINY_SEEDLE_H

#include "Product.h"

class Seedle : public Product{
private:
    int ammount;
public:
    Seedle(int id, const std::string &name, float price, int ammount);

    std::string productInfo() override;

    float getTotalPrice() override;

    int getAmmount() const;
};


#endif //ROSLINY_SEEDLE_H
