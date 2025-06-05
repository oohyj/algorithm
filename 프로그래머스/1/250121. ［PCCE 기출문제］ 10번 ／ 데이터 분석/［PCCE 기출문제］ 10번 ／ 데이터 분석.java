import java.util.*;

class Solution {
    public int[][] solution(int[][] data, String ext, int val_ext, String sort_by) {
        
        ArrayList<int[]> filtered = new ArrayList<>();
        
        int n = data.length;
        int extidx = changeNum(ext);
        int sort = changeNum(sort_by);
        
        for(int[] d : data){
            if(d[extidx] < val_ext){
                filtered.add(d);
            }
        }
        
       filtered.sort(Comparator.comparingInt(o ->o[sort]));
        
        int[][] answer = new int[filtered.size()][];
        for(int i =0; i<filtered.size(); ++i){
            answer[i] = filtered.get(i);
        }
        

        
        return answer;
    }
    
    private int changeNum(String ext){
        if(ext.equals("code")){
            return 0;
        }
        else if(ext.equals("date")){
            return 1;
        }
        else if(ext.equals("maximum")){
            return 2;
        }
        else{ // remain
            return 3;
        }
    }
}