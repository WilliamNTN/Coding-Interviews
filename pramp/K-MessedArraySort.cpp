
//Given an array of integers arr where each element is at most k places
//away from its sorted position, code an efficient function sortKMessedArray
//that sorts arr. For instance, for an input array of size 10 and k = 2
//an element belonging to index 6 in the sorted array will be located at
//either index 4, 5, 6, 7 or 8 in the input array.

//Time: O(n), Space: O(k) "Not considering the ans vector"

vector<int> sortKMessedArray( const vector<int>& arr, int k ){
  vector<int> ans(arr.begin(),arr.end());
  priority_queue<int> pq;
  
  for(int i = 0; i < k+1; i++)
    pq.push(-arr[i]);
 
  for(int i = 0; i < arr.size() ; i++){
    if(i > 0 && (i+k) < arr.size()) pq.push(-arr[i+k]);
    int minValue = pq.top(); pq.pop();
    ans[i] = -minValue;
  }
  return ans;
}