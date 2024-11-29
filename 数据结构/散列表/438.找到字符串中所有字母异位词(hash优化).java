class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> ans = new ArrayList<>();
        if (s == null || p == null || s.length() == 0 || p.length() == 0 || s.length() < p.length()) {
            return ans;
        }

        int lenS = s.length();
        int lenP = p.length();

        int[] pCharCnt = new int[26];
        int[] sCharCnt = new int[26];
        for(int i=0;i<lenP;i++){
            ++pCharCnt[p.charAt(i)-'a'];
            ++sCharCnt[s.charAt(i)-'a'];
        }
      
        if (Arrays.equals(pCharCnt, sCharCnt)) {
            ans.add(0);
        }

        for (int i = 1; i <= lenS - lenP; i++) {
            char rmChar = s.charAt(i - 1);
            char newChar = s.charAt(i + lenP - 1);

            --sCharCnt[rmChar-'a'];
            ++sCharCnt[newChar-'a'];

            if (Arrays.equals(pCharCnt, sCharCnt)) {
                ans.add(i);
            }
        }
        return ans;
    }
}