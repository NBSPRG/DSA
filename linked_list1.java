import java.util.LinkedList;

public class Linked_list {

    public static void main(String[] args) {
        LinkedList <String> ll1 = new LinkedList<>();
        ll1.addFirst("math");
        ll1.addFirst("a");
        ll1.addFirst("is");
        int size = ll1.size();

        for(int i = 0; i < size; i++)
        {
            System.out.print(ll1.get(i) + " -> ");
        }
        System.out.println("null");

        ll1.addFirst("this");
        ll1.removeLast();

        for(int i = 0; i < size; i++)
        {
            System.out.print(ll1.get(i) + " -> ");
        }
        System.out.println("null");

        System.out.println(ll1);

    }

}
