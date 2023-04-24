#include <algorithm>
#include <set>
#include <stdio.h>

const long long MAX_RANGE = 1e18;

class Segment {
public:
  int l, r;

  int get_size() { return r - l + 1; }
};

class TestCase {
public:
  int n, desired_range;
  Segment *segments;

  void get_input() {
    scanf("%d %d", &this->n, &this->desired_range);

    this->segments = new Segment[n];

    for (int i = 0; i < this->n; i++) {
      scanf("%d", &this->segments[i].l);
    }

    for (int i = 0; i < n; i++) {
      scanf("%d", &this->segments[i].r);
    }
  }

  long long get_range_cost(long long length, long long count, Segment &seg) {
    return 2 * count + seg.r - (length - this->desired_range);
  }

  void answer() {
    std::multiset<int> set;
    long long blacked_range = 0;
    long long range_count = 0;
    long long ans = MAX_RANGE;
    Segment *top_seg = NULL;

    for (int i = 0; i < this->n; i++) {
      // remove old ones
      while (blacked_range >= this->desired_range) {
        if (top_seg) {
          ans = std::min(
              ans, this->get_range_cost(blacked_range, range_count, *top_seg));
        }
        auto minimum_range = set.begin();
        blacked_range -= *minimum_range;
        range_count--;
        set.erase(minimum_range);
      }

      // insert new one
      Segment &seg = this->segments[i];
      set.insert(seg.get_size());
      top_seg = &seg;

      blacked_range += seg.get_size();
      range_count++;

      if (blacked_range >= this->desired_range) {
        ans = std::min(ans,
                       this->get_range_cost(blacked_range, range_count, seg));
      }
    }
    // remove old ones
    while (blacked_range >= this->desired_range) {
      if (top_seg) {
        ans = std::min(
            ans, this->get_range_cost(blacked_range, range_count, *top_seg));
      }
      auto minimum_range = set.begin();
      blacked_range -= *minimum_range;
      range_count--;
      set.erase(minimum_range);
    }

    if (ans == MAX_RANGE) {
      printf("-1\n");
      return;
    }

    printf("%lld\n", ans);
  }
};

int main() {
  int test;
  scanf("%d", &test);

  while (test--) {
    TestCase t;
    t.get_input();
    t.answer();
  }
}
