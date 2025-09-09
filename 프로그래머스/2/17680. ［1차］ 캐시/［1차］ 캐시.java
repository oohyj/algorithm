import java.util.*;

class Solution {
    public int solution(int cacheSize, String[] cities) {
        int answer = 0;
        if(cacheSize == 0) return cities.length * 5;
        
        Set<String> cache = new LinkedHashSet<>(cacheSize);
        
        for(String raw : cities){
            String city = raw.toLowerCase();
            
            if(cache.contains(city)){
                answer += 1;
                cache.remove(city);
                cache.add(city);
            }else{
                if(cache.size() == cacheSize){
                    String oldest = cache.iterator().next();
                    cache.remove(oldest);
                }
                answer +=5;
                cache.add(city);
            }
        }
    
        
        return answer;
    }
}