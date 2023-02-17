import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Objects;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        ArrayList<Integer> arr = new ArrayList<>();
        StringBuilder sb = new StringBuilder();
        int total = 0;
        int k = 0;

        for (int i = 0; i < N; ++i){
            k = Integer.parseInt(br.readLine());
            arr.add(k);
            total += k;
        }

        arr.sort(Comparator.naturalOrder());

        int result = 1;
        int numfin = 0;
        int count = 1;
        int stats = 0;

        if (N == 1){
            numfin = arr.get(0);
        } else {
            for (int i = 1; i < N ; ++i){
                if (Objects.equals(arr.get(i - 1), arr.get(i))){
                    count++;
                }
                if ((!Objects.equals(arr.get(i - 1), arr.get(i))) || (i == (N-1))) {
                    if (count > result) {
                        result = count;
                        numfin = arr.get(i-1);
                        stats = 0;
                    }
                    if ((count == result) && (stats < 2)){
                        stats++;
                        numfin = arr.get(i-1);
                    }
                    count = 1;
                }
            }
        }

        sb.append((int)Math.round((double)total/N));
        sb.append("\n");
        sb.append(arr.get(N/2)).append("\n"); // 2
        sb.append(numfin).append("\n"); // 3
        sb.append(arr.get(N-1) - arr.get(0)); // 4
        System.out.println(sb);

    }
}