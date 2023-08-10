import java.util.*;
public class Solution {
    //Insert one char from stringstream

    private Queue<Character> q = new LinkedList<>();
    private Map<Character, Integer> s = new HashMap<>();

    public void Insert(char ch)
    {
        if(!s.containsKey(ch)){
            q.offer(ch);
            s.put(ch,1);
        }else{
            s.put(ch, s.get(ch)+1);  
        }
    }
  //return the first appearence once char in current stringstream
    public char FirstAppearingOnce()
    {
        while(!q.isEmpty() && s.get(q.peek())>1){
            q.poll();
        }

        if(q.isEmpty()){
            return '#';
        }else{
            return q.peek();
        }
    }
}
