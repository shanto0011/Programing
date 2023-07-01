import java.util.List;
import java.util.Scanner;

class Actionable {
    public static Product chooseProduct(List<Product> productList) {
        Scanner scanner = new Scanner(System.in);
        StringBuilder productListStr = new StringBuilder();
        System.out.println("Available Products:");
        for (Product product : productList) {
            productListStr.append(product.getDisplayName());
        }
        System.out.println(productListStr.toString());
        System.out.println("------------------");

        String choice = scanner.next();

        for (Product product : productList) {
            if (product.getShortName().equalsIgnoreCase(choice)) {
                return product;
            }
        }

        System.out.println("Product not found!");
        return null;
    }

    public static boolean checkout(Cart cart) {
        if (cart.isEmpty()) {
            return false;
        }

        int total = cart.getTotal();

        Scanner scanner = new Scanner(System.in);
        System.out.println("Pay in Cash");
        int paid = scanner.nextInt();

        if (paid >= total) {
            System.out.println("Change " + (paid - total));
            System.out.println("Thank you for shopping!");
            return true;
        } else {
            System.out.println("Not enough cash!");
            return false;
        }
    }
}
