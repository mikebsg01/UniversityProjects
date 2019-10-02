class ArabicNumber {

  private int arabicnum;

  ArabicNumber(int arabicnum) {
    this.arabicnum = arabicnum;
  }

  public ArabicNumber setArabicNumber(int arabicnum) {
    this.arabicnum = arabicnum;
    return this;
  }

  private String convertToRoman() {
    int n = this.arabicnum;
    String inRoman = "";

    while (n > 0) {

      if (n >= 1000) {
        n -= 1000;
        inRoman += "M";
      }
      else if (n >= 900) {
        n -= 900;
        inRoman += "CM";
      }
      else if (n >= 500) {
        n -= 500;
        inRoman += "D";
      }
      else if (n >= 400) {
        n -= 400;
        inRoman += "CD";
      }
      else if (n >= 100) {
          n  -= 100;
          inRoman += "C";
      }
      else if (n >= 90) {
          n -= 90;
          inRoman += "XC";
      }
      else if (n >= 50) {
          n -= 50;
          inRoman += "L";
      }
      else if (n >= 40) {
          n -= 40;
          inRoman += "XL";
      }
      else if (n >= 10) {
          n -= 10;
          inRoman += "X";
      }
      else if (n == 9) {
          n -= 9;
          inRoman += "IX";
      }
      else if (n >= 5) {
          n -= 5;
          inRoman += "V";
      }
      else if (n == 4) {
          n -= 4;
          inRoman += "IV";
      }
      else if (n >= 1) {
          --n;
          inRoman += "I";
      }
    }
    return inRoman;
  }

  public String getInRoman() {
    return convertToRoman();
  }
}