public class Item extends Product {
    int product_quantity;
    private Product product;

    Item() {

    }

    Item(Product prod, int prod_q) {
        this.product = prod;
        this.product_quantity = prod_q;
    }

    public int getItemPrice() {
        return product_quantity * product.getPrice();
    }

    public String getItemInfo() {
        return product_quantity + " X " + product.getName() + " BD. " + (product_quantity * product.getPrice()) + "\n";
    }
}
