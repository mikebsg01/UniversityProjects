class Employee {

  private String name;
  private int id;

  Employee(String name, int id) {
    this.name = name;
    this.id = id;
  }

  public String getName() {
    return name;
  }

  public int getId() {
    return id;
  }

  public String toString() {
    return "{ \"id\": " + id + ", \"name\": \"" + name + "\" }";
  }
}
