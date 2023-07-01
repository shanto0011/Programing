import java.util.HashMap;
import java.util.Map;

class Cart {
    private Map<Integer, Item> items;

    public Cart() {
        items = new HashMap<>();
    }

    public void addProduct(Product product) {
        if (!items.containsKey(product.getId())) {
            Item newItem = new Item(product, 1);
            items.put(product.getId(), newItem);
        } else {
            Item item = items.get(product.getId());
            item.product_quantity += 1;
        }
    }

    public int getTotal() {
        int total = 0;
        for (Item item : items.values()) {
            total += item.getItemPrice();
        }
        return total;
    }

    public String viewCart() {
        if (items.isEmpty()) {
            return "Cart is empty";
        }

        StringBuilder itemizedList = new StringBuilder();
        int cartTotal = getTotal();

        for (Item item : items.values()) {
            itemizedList.append(item.getItemInfo());
        }

        return itemizedList.toString() + "\nTotal Amount: Rs. " + cartTotal + "\n";
    }

    public boolean isEmpty() {
        return items.isEmpty();
    }
}
