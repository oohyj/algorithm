import java.util.*;
class Solution {
    
    static int n , m; // 숫자 범위 , 질의 개수
    static int[][] q; // 각 질의에 포함된 5개의 숫자
    static int[] hits; // 현재까지 고른 숫자들이 질의별로 맞춘 개수 누적
    static int[] ans; // 각 질의에 대한 정답
    static boolean[] chosen; //숫자 (1~N)까지 골랐는지
    static List<Integer> picked = new ArrayList<>(5); //현재까지 고른 숫자 목록
    static int answer;
    
    static int remHitMaxForQuery(int i , int from){
        int cnt = 0;
        for(int t = 0; t < 5; ++t){
            int x = q[i][t];
            if(!chosen[x] && x >= from) cnt++;
        }
        return cnt;
    }
        
    static boolean feasible(int from){
        for(int i = 0; i<m; ++i){
            if(hits[i] > ans[i]) return false;
            int remMax = remHitMaxForQuery(i , from); // 앞으로 맞출 수 있는 최대치
            if(hits[i] + remMax < ans[i]) return false;
        }
        return true;
    }
    
    static void dfs(int start){
        if(picked.size() == 5){
            for(int i =0; i<m; ++i) {if(hits[i] != ans[i]) return;}
                answer++;
                return;
            
        }
        
        int left = 5 - picked.size(); // 내가 이번 턴에서 고를 수 있는 숫자 개수
        if(start > n - left +1) return; // 남은 숫자로 채울 수 없으면 컷 , 내가 1부터 숫자를 고르기 시작해서 지금 8인데 left가 4야 이러면 남은 숫자 다 써도 채우지 못함
        if(!feasible(start)) return; // 가지치기 : 더 진행해도 불가능하면 컷
        
        for(int x = start; x <=n; ++x){
            picked.add(x);
            chosen[x] = true; 
            for(int i =0; i<m; ++i){
                // x가 해당 질의 q[i]에 포함되면 hit[i] 증가
                for(int t = 0; t <5; ++t){
                    if(q[i][t] == x){
                        hits[i]++;
                        break;
                    }
                }
            }
            
            dfs(x+1); //이제 x 보다 1 큰수를 고르기 시작
            
            for(int i =0; i<m; ++i){
                for(int t =0; t <5; ++t){
                    if(q[i][t] == x) {
                        hits[i]--;
                        break;
                    }
                }
            }
            chosen[x] = false;
            picked.remove(picked.size() -1);
            if(x+1 > n - (left-1) +1) break;
        }
    }
    
    public int solution(int N, int[][] Q, int[] result) {
        n = N;
        q = Q;
        m = q.length;
        hits = new int[m];
        chosen = new boolean[n+1];
        ans = result;
        picked.clear();
        answer = 0;
        dfs(1);
        
        return answer;
    }
}