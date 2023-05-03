#include <stdio.h>
#include <stdlib.h>

struct Robot {
  int current;
  int speed;
  int task_count;
  int *tasks;
};

struct TestCase {
  int n;
  int *r;
  struct Robot robot1, robot2;
};

int min(int a, int b) { return a < b ? a : b; }

void rb_init(struct Robot *r, int n) {
  r->current = 0;
  r->task_count = 0;
  r->tasks = malloc(sizeof(int) * n);
}

void rb_add_task(struct Robot *r, int color) {
  r->tasks[r->task_count] = color;
  r->task_count++;
}

void rb_print_tasks(struct Robot *r) {
  printf("%d ", r->task_count);
  for (int i = 0; i < r->task_count; i++) {
    printf("%d ", r->tasks[i]);
  }
  printf("\n");
}

struct Robot *rb_get_faster_one(struct Robot *rb1, struct Robot *rb2,
                                int count) {
  int rb1_time = min(rb1->current + rb1->speed * count, rb2->current);
  int rb2_time = min(rb2->current + rb2->speed * count, rb1->current);

  return rb1_time < rb2_time ? rb1 : rb2;
}

void tc_init(struct TestCase *tc) {
  rb_init(&tc->robot1, tc->n);
  rb_init(&tc->robot2, tc->n);
}

void tc_get_input(struct TestCase *tc) {
  scanf("%d %d %d", &tc->n, &tc->robot1.speed, &tc->robot2.speed);
  tc->r = malloc(sizeof(int) * tc->n);
  for (int i = 0; i < tc->n; i++) {
    scanf("%d", &tc->r[i]);
  }
}

int cmp_int_reverse(const void *_a, const void *_b) {
  int a = *(int *)_a;
  int b = *(int *)_b;

  if (b > a) {
    return 1;
  }

  if (a > b) {
    return -1;
  }
  return 0;
}

void tc_solve(struct TestCase *tc) {
  qsort(tc->r, tc->n, sizeof(int), cmp_int_reverse);

  for (int i = 0; i < tc->n; i++) {
    struct Robot *robot = rb_get_faster_one(&tc->robot1, &tc->robot2, tc->r[i]);
    rb_add_task(robot, tc->r[i]);
  }

  rb_print_tasks(&tc->robot1);
  rb_print_tasks(&tc->robot2);
}

void tc_clean(struct TestCase *tc) { free(tc->r); }

int main() {
  int t;
  scanf("%d", &t);

  while (t--) {
    struct TestCase tc;
    tc_init(&tc);
    tc_get_input(&tc);
    tc_solve(&tc);
    // tc_clean(&tc);
  }
}
