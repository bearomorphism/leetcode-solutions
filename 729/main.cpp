class MyCalendar
{
private:
  map<int, int> bookings;

public:
  bool book(int start, int end)
  {
    auto it = bookings.lower_bound(start);
    if (it != bookings.end() && it->first < end || it != bookings.begin() && (--it)->second > start)
      return false;
    bookings[start] = end;
    return true;
  }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */