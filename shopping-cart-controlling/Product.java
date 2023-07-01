public class Product implements Displayable {
    private int product_id;
    private String product_name;
    private int product_price;

    Product() {

    }

    Product(int p_id, String product_name, int product_price) {
        product_id = p_id;
        this.product_name = product_name;
        this.product_price = product_price;
    }

    public int getId() {
        return product_id;
    }

    public String getName() {
        return product_name;
    }

    public int getPrice() {
        return product_price;
    }

    public String getDisplayName() {

        return product_name + " : BD. " + String.valueOf(product_price) + "\n";
    }

    public String getShortName() {
        // return product_name.substring(0, 1);
        return product_name;
    }

}
