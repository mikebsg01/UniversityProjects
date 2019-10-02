class DataTable {

  private String strDataTable;

  DataTable() {
    strDataTable = "";
  }

  private String customStringFormat(int maxNumOfChars, String str) {
    int n = str.length();

    if (n > maxNumOfChars) {
      return str.substring(0, maxNumOfChars);
    }
    else if (n < maxNumOfChars) {
      int remaining = maxNumOfChars - n,
          i;

      for (i = 0; i < remaining; ++i) {
        str += " ";
      }
    }
    return str;
  }

  public DataTable addSeparator(int length) {
    int n = strDataTable.length(), i;

    if (n > 0 && strDataTable.charAt(n - 1) != '\n') {
      strDataTable += "\n";
    }

    for (i = 0; i < length; ++i) {
      strDataTable += "=";
    }
    strDataTable += "\n";
    return this;
  }

  public DataTable addColumn(String data, int maxNumOfChars) {
    strDataTable += "| " + customStringFormat(maxNumOfChars, data) + " |";
    return this;
  }

  public DataTable nextRow() {
    strDataTable += "\n";
    return this;
  }

  public String toString() {
    if (strDataTable != "") {
      return strDataTable;
    }

    return "\n\t\t<< La tabla de datos esta vacia >>\n\n";
  }
}
