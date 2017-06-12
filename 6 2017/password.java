/**
* Problem E: My Password is a Palindromic Prime Number
* Status: YES
* Issue: Maths, Number Theory
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.util.HashMap;
import java.util.Map;

public class password {

    static StringBuilder ans;
    
    public static void main(String[] args) throws IOException {
         BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int casos = Integer.parseInt(br.readLine());

            for (int i = 0; i < casos; i++) {
                ans = new StringBuilder("");
                solve(Integer.parseInt(br.readLine()));
                ans.insert(1, '.');
                System.out.println(ans);
            }
           
    }

   static void solve(int n) {
        Map<Integer, Integer> mp = new HashMap<Integer, Integer>();
        int rem = 1;
        int cont = 0;
        while (!mp.containsKey(rem)) {
            mp.put(rem, cont);
            ans.append((int)rem / n);
            rem = rem % n;
            rem = rem * 10;
            cont++;
        }
    }
}
