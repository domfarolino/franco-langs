int binarySearch(const vector<int>& haystack, int needle) {
  int l = 0, r = haystack.size()-1, m;

  while (l <= r) {
    m = (r - l)/2 + l;
    
    if (haystack[m] > needle) {
      r = m-1;
    } else if (haystack[m] < needle) {
      l = m+1;
    } else (haystack[m] == needle) {
      return m;
    }
  }

  return -1;
}