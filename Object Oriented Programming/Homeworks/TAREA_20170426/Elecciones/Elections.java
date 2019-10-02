import java.util.Map;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

class Elections {

  private String[] candidates;
  private int numberOfDistricts;
  private HashMap<String, HashMap<Integer, Integer>> votes;

  public Elections(String[] candidates, int numberOfDistricts) {
    votes = new HashMap<String, HashMap<Integer,Integer>>();
    setCandidates(candidates);
    setNumberOfDistricts(numberOfDistricts);
  }

  public Elections setCandidates(String[] candidates) {
    this.candidates = candidates;
    return this;
  }

  public Elections setNumberOfDistricts(int numberOfDistricts) {
    this.numberOfDistricts = numberOfDistricts;
    return this;
  }

  public Elections setElectionsByDistrict(String candidate, int district, int numberOfVotes) {
    HashMap<Integer, Integer> v;

    if (votes.containsKey(candidate)) {
      v = votes.get(candidate);
      v.put(district, numberOfVotes);
    } else {
      v = new HashMap<Integer,Integer>();
      v.put(district, numberOfVotes);
    }

    votes.put(candidate, v);
    return this;
  }

  public int getVotesByCandidate(String candidate) {
    if (votes.containsKey(candidate)) {
      int sum = 0;

      HashMap<Integer,Integer> mapVotesByCandidate = votes.get(candidate);

      for (Map.Entry<Integer, Integer> entryVotesByCandidate : mapVotesByCandidate.entrySet()) {
        sum += entryVotesByCandidate.getValue();
      }
      return sum;
    }
    return -1;
  }

  public int getTotalVotes() {
    int total = 0, 
        numberOfVotes;

    for (String candidate : candidates) {
      numberOfVotes = getVotesByCandidate(candidate);

      if (numberOfVotes < 0) {
        return -1;
      }
      total += numberOfVotes;
    }
    return total;
  }

  public double getPercentageOfVotesByCandidate(String candidate) {
    if (votes.containsKey(candidate)) {
      double sum, totalVotes, percentage;

      sum = 0;
      HashMap<Integer,Integer> mapVotesByCandidate = votes.get(candidate);

      for (Map.Entry<Integer, Integer> entryVotesByCandidate : mapVotesByCandidate.entrySet()) {
        sum += entryVotesByCandidate.getValue();
      }

      totalVotes = (double) this.getTotalVotes();
      percentage = (sum / totalVotes) * 100;
      return percentage;
    }
    return -1;
  }

  public String getWinner() {
    double percentage;

    for (String candidate : candidates) {
      percentage = getPercentageOfVotesByCandidate(candidate);

      if (percentage >= 50.00) {
        return candidate;
      }
    }
    return null;
  }

  public String toString() {
    String s = "";
    String winner;
    List<String> candidateList = new ArrayList<String>();
    int[][] votesByCandidateMatrix = new int[this.candidates.length][this.numberOfDistricts];
    int i, j;
    i = 0;

    for (Map.Entry<String, HashMap<Integer, Integer>> entryVotes : votes.entrySet()) {
      candidateList.add(entryVotes.getKey());
      HashMap<Integer,Integer> votesByCandidate = entryVotes.getValue();
      j = 0;

      for (Map.Entry<Integer, Integer> entryVotesByCandidate : votesByCandidate.entrySet()) {
        votesByCandidateMatrix[i][j] = entryVotesByCandidate.getValue();
        ++j;
      }
      ++i;
    }

    s += String.format(" %11s ", "Distrito");

    for (String candidate : candidateList) {
      s += String.format(" %11s ", candidate);
    }

    s += "\n";

    for (j = 0; j < votesByCandidateMatrix[0].length; ++j) {
      s += String.format(" %11d ", j + 1);

      for (i = 0; i < votesByCandidateMatrix.length; ++i) {
        s += String.format(" %11d ", votesByCandidateMatrix[i][j]);
      }
      s += "\n";
    }

    s += "\n";
    s += "Total de votos: " + this.getTotalVotes() + "\n";
    s += "\n";

    for (String candidate : candidateList) {
      s += "Votos " + candidate + ": " + String.format("%10d", this.getVotesByCandidate(candidate)) + " ";
      s += "(" + String.format("%.2f", this.getPercentageOfVotesByCandidate(candidate)) + "%)\n";
    }

    s += "\n";

    winner = getWinner();

    if (winner != null) {
      s += ">>> Ganador de las elecciones: " + winner + "\n";
    } else {
      s += ">>> No hay ganador definitivo.\n";
    }
    return s;
  }
}