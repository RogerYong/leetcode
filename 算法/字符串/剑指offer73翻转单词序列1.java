import java.util.*;
public class Solution {

    void reverse(char[] ch, int l, int r) {
        while (l < r) {
            swap(ch, l, r);
            l++;
            r--;
        }
    }

    void swap(char[] ch, int i, int j) {
        char tmp = ch[i];
        ch[i] = ch[j];
        ch[j] = tmp;
    }
    public String ReverseSentence(String str) {

        if (str == null || str.isEmpty()) {
            return "";
        }
        char[] ch = str.toCharArray();
        reverse(ch, 0, ch.length - 1);

        for (int i = 0; i < str.length();) {
            while (i < str.length() && ch[i] == ' ') {
                i++;
            }
            int r = i;
            while (r < str.length() && ch[r] != ' ') {
                r++;
            }

            reverse(ch, i, r - 1);
            i = r;
        }
        return String.valueOf(ch);
    }
}
