class Solution {
    public int[] solution(int[] sequence, int k) {
        int[] answer = {};
        
        int start = 0 , end = 0 , sum = 0;
        
        for(int i =0; i<sequence.length; ++i){
            end = i;
            sum += sequence[end];
            
            while(sum > k){
                sum -= sequence[start++];
            }
            
            if(sum == k){
                if(answer.length == 0 || end - start < answer[1] - answer[0]){
                    answer = new int[] { start , end};
                }
            }
            
        }
        return answer;
    }
}