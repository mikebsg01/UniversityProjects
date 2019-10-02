import java.util.ArrayList;
import java.util.List;

class Lists {

  /**
   * List Class
   * @author Michael Serrato - mikebsg01@gmail.com
   */

  // Class Attributes
  private List<Integer> list;
  private final int MAX_SIZE = 10; // It can change 

  Lists() {
    createEmptyList();
  }

  public void createEmptyList() {
    list = new ArrayList<Integer>();
  }

  public int getSize() {
    return list.size();
  }

  public boolean isEmpty() {
    if (getSize() > 0) {
      return false;
    }
    return true;
  }

  public boolean isFull() {
    if (getSize() == MAX_SIZE) {
      return true;
    }
    return false;
  }

  public Lists add(int num) {
    if (isFull()) {
      System.out.println("\n\tEl valor no pudo ser agregado, la lista esta llena.\n");
      return this;
    }

    list.add(num);
    return this;
  }

  public List<Integer> getAll() {
    return list;
  }

  public Lists changeValue(int pos, int newVal) {
    if (pos < 0 || pos >= getSize()) {
      throw new ListsException("La posicion se encuentra fuera de rango.");
    }

    int i = 0;
    List<Integer> tmpList = new ArrayList<Integer>();

    for (int val : getAll()) {
      if (pos == i) {
        tmpList.add(newVal);
      } else {
        tmpList.add(val);
      }
      ++i;
    }

    list = tmpList;
    return this;
  }
}

class ListsException extends RuntimeException {

  private String msg;

  ListsException() {
    msg = "Lists Runtime Exception";
  }

  ListsException(String msg) {
    this.msg = msg;
  }

  public String getMessage() {
    return msg;
  }
}