import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        List<Product> allProducts = new ArrayList<>();
        allProducts.add(new Product(1, "Iphone_7", 34000));
        allProducts.add(new Product(2, "Samsunge_Ultra_S20", 76000));
        allProducts.add(new Product(3, "Huawei_y6", 12000));
        allProducts.add(new Product(4, "Xiomi_Note10", 19000));
        allProducts.add(new Product(5, "Honor_50x", 40000));

        char action;
        ShoppingCart cart = new ShoppingCart();

        while (true) {
            System.out.println("Select an action - (a)dd item, (v)iew cart, (c)heckout");
            Scanner scanner = new Scanner(System.in);
            action = scanner.next().charAt(0);

            if (action == 'a') {
                Product product = Actionable.chooseProduct(allProducts);
                if (product != null) {
                    System.out.println("Added to the Cart: " + product.getDisplayName());
                    cart.addProduct(product);
                }
            } else if (action == 'v') {
                System.out.println(" ------------------- ");
                System.out.println(cart.viewCart());
                System.out.println(" ------------------------ ");
            } else {
                System.out.println(cart.viewCart());
                if (Actionable.checkout(cart)) {
                    break;
                }
            }
        }
    }
}