#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class ProductManager{
    public:
    virtual void displayProductDetails(int ProductID){
        cout << "Product ID: " << ProductID <<endl;
    }
    virtual ~ProductManager(){}

};
class AbstractCart : public ProductManager{
    protected:
    vector<int>product;
    public:
    virtual ~AbstractCart(){}
    void addToCart(int ProductID){
        product.push_back(ProductID);
        cout << "Product: " << ProductID << " added to cart." << endl;
    };
    void displayCart(){
        if(product.empty()){
            cout << "Cart is empty." <<endl;
        }
        for(int a : product){
            cout << "Product ID: " << a << " ";
        }
    }
    virtual void checkout() = 0;
    void removeFromCart(int ProductID){
        product.erase(remove(product.begin(), product.end(), 30), product.end());
        cout << "Product: " << ProductID << "remove from cart." <<endl;
    }
};
class OnlineStore : public AbstractCart{
    public:
    void displayProductDetails(int ProductID)override{
        cout << "Product ID: " << ProductID << endl;
    }
    void checkout()override{
        if(product.empty()){
            cout << "Checkout failed...Cart is empty" <<endl;
        }
        else{
        cout << "Payment is sucssesfully" <<endl;
        }
    }

};
class MobileApp : public AbstractCart{
    public:
    void displayProductDetails(int ProductID)override{
        cout << "Product Id: " << ProductID << endl;
    }
    void checkout()override{
        if(product.empty()){
            cout << "Checkout failed...Cart is empty" <<endl;
        }
        else{
        cout << "Payment is sucssesfully" <<endl;
        }
    }

};
int main(){
     OnlineStore onlineStore;
    onlineStore.displayProductDetails(101);
    onlineStore.addToCart(101);
    onlineStore.addToCart(102);
    onlineStore.displayCart();
    onlineStore.checkout();

    MobileApp mobileApp;
    mobileApp.displayProductDetails(201);
    mobileApp.addToCart(201);
    mobileApp.removeFromCart(202);
    mobileApp.displayCart();
    mobileApp.checkout();
}
