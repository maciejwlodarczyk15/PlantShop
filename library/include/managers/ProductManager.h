#ifndef ROSLINY_PRODUCTMANAGER_H
#define ROSLINY_PRODUCTMANAGER_H

#include <memory>
class ProductRepository;
class Product;
class OrderManager;
class ProductManager {
private:
    std::shared_ptr<ProductRepository> productRepo;
public:
    ProductManager(const std::shared_ptr<ProductRepository> &productRepo);
    void createProductSeed(int id, std::string name, float price, float weight);
    void createProductSeedle(int id, std::string name, float price, int amount);
    void deleteProduct(int id, std::shared_ptr<OrderManager> orderManager);
    std::string productReport();
    std::shared_ptr<Product> getProduct(int id);
    bool productExists(int id);
};


#endif //ROSLINY_PRODUCTMANAGER_H
