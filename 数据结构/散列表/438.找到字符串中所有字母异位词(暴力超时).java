class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> ans = new ArrayList<>();
        if(s==null || p==null || s.length()==0 || p.length()==0){
            return ans;
        }
 
        int lenS = s.length();
        int lenP = p.length();

        Map<Character, Integer> pCharCnt = getCharCnt(p, 0, lenP-1);


        for(int i=0;i<= lenS-lenP;i++){
            Map<Character, Integer> curCharCnt = getCharCnt(s, i, i+lenP-1);
            if(isSame(pCharCnt, curCharCnt)){
                ans.add(i);
            } 
        }
        return ans;
    }


    public Map<Character, Integer> getCharCnt(String s, int left, int right){
        Map<Character, Integer> charCnt = new HashMap<>();
        if(s==null || s.length()==0 ){
            return charCnt;
        }
        for(int i=left;i<=right && i>=0 && i<s.length();i++){
            char c = s.charAt(i);
            int cnt = charCnt.getOrDefault(c, 0);
            cnt = cnt + 1;
            charCnt.put(c, cnt);
        }
        return charCnt;
    }

    public boolean isSame(Map<Character, Integer> a, Map<Character, Integer> b){
        if(a==null || b==null){
            return a==b;
        }

        Set<Character> aKeys = a.keySet();
        Set<Character> bKeys = b.keySet();

        if(aKeys.containsAll(bKeys) && bKeys.containsAll(aKeys)){
            for(Character c: aKeys){
                Integer aCnt = a.get(c);
                Integer bCnt = b.get(c);
                if(!aCnt.equals(bCnt)){
                    return false;
                }
            }
            return true;
        }else{
            return false;
        }
    }
}