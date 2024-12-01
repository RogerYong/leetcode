class Solution {
    public String minWindow(String s, String t) {
        String ans = "";


        Map<Character, List<Integer>> sCharToidx = new HashMap<>();
        Map<Character, Integer> tCharCnt = new HashMap<>();
        for(int i=0;i<t.length();i++){
            char c= t.charAt(i);
            Integer cnt = tCharCnt.getOrDefault(c, 0);
            cnt++;
            tCharCnt.put(c, cnt);
        }

        for(int i=0;i<s.length();i++){
            char c= s.charAt(i);
            List<Integer> idxs = sCharToidx.getOrDefault(c, new ArrayList<>());
            idxs.add(i);
            sCharToidx.put(c, idxs);
            String curAns = getMinWindow(s, tCharCnt, sCharToidx, i);
            if(curAns.length()!=0 && (ans.length()==0 || curAns.length() < ans.length())){
                ans = curAns;
            }
        }
        return ans;
    }

    String getMinWindow(String s, Map<Character, Integer> tCharCnt, Map<Character, List<Integer>> sCharToidx, int curIdx){
        int minLeft = -1;
        if(tCharCnt.isEmpty()){
            return "";
        }

        for(Character c : tCharCnt.keySet()){
            if(sCharToidx.containsKey(c) && sCharToidx.get(c).size()>= tCharCnt.get(c)){
                Integer cnt = tCharCnt.get(c);
                List<Integer> idxs = sCharToidx.get(c);
                Integer minIdx = idxs.get(idxs.size() - cnt);
                if(minLeft==-1){
                    minLeft = minIdx;
                }else{
                    minLeft = Math.min(minLeft, minIdx);
                }
            }else{
                // 表示不存在子串
                return "";
            }
        }
        return s.substring(minLeft, curIdx+1);
    }
}