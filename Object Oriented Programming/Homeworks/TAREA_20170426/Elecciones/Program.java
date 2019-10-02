import java.util.Formatter;

class Program {
	public static void main(String[] arg) {
    String[] candidates = new String[] { "Candidato A", "Candidato B", "Candidato C", "Candidato D" };
    int numberOfDistricts = 5;
    Integer[][] votes = new Integer[][] {
      new Integer[] { 194, 48, 206, 45 },
      new Integer[] { 180, 20, 320, 16 },
      new Integer[] { 221, 90, 140, 20 },
      new Integer[] { 432, 50, 821, 14 },
      new Integer[] { 820, 61, 946, 18 }
    };

    Elections elections = new Elections(candidates, numberOfDistricts);

    for (int i = 0; i < candidates.length; ++i) {
      for (int j = 1; j <= numberOfDistricts; ++j) {
        elections.setElectionsByDistrict(candidates[i], j, votes[j - 1][i]);
      }
    }

    System.out.println(elections.toString());
	}
}