#pragma once

#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::queue;
using std::unordered_map;
using std::unordered_set;
using std::vector;

class Solution {
 public:
  // This problem is simply checking whether a directed graph contains a cycle.
  // Disconnected components are allowed.
  // For example, 1 -> 2 and 3 -> 4 still allow taking all courses

  // Time: O(V + E) | Space: O(V + E)
  // where V is number of courses, E is number of prerequisites
  // Topological sort using Kahn's algorithm (BFS)
  // https://www.youtube.com/watch?v=EUDwWbvtB_Q
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    // Build the graph
    unordered_map<int, vector<int>> m;
    // Track in-degree (number of prerequisites) for each course
    vector<int> indegree(numCourses, 0);

    // Populate graph and indegree array
    for (const auto& prereq : prerequisites) {
      int course = prereq[0];
      int prerequisite = prereq[1];
      m[prerequisite].push_back(course);
      indegree[course]++;
    }

    // Initialize queue with all courses that have no prerequisites (in-degree = 0)
    queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
      if (indegree[i] == 0) {
        q.push(i);
      }
    }

    // Process courses using topological sort (Kahn's algorithm)
    while (!q.empty()) {
      // Take a course with no remaining prerequisites
      int course = q.front();
      q.pop();

      // Mark this course as completed

      // For each course that depends on the current course
      for (int dependent : m[course]) {
        // Reduce indegree for dependent courses
        indegree[dependent]--;
        // If indegree becomes 0, add to queue to consider next
        if (indegree[dependent] == 0) {
          q.push(dependent);
        }
      }
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      // Build the graph
      unordered_map<int, vector<int>> m;
      // Track in-degree (number of prerequisites) for each course
      vector<int> indegree(numCourses, 0);

      // Populate graph and indegree array
      for (const auto& prereq : prerequisites) {
        int course = prereq[0];
        int prerequisite = prereq[1];
        m[prerequisite].push_back(course);
        indegree[course]++;
      }

      // Initialize queue with all courses that have no prerequisites (in-degree = 0)
      queue<int> q;
      for (int i = 0; i < numCourses; ++i) {
        if (indegree[i] == 0) {
          q.push(i);
        }
      }

      int completed = 0

          // Process courses using topological sort (Kahn's algorithm)
          while (!q.empty()) {
        // Take a course with no remaining prerequisites
        int course = q.front();
        q.pop();

        // Mark this course as completed
        completed++;

        // For each course that depends on the current course
        for (int dependent : m[course]) {
          // Reduce indegree for dependent courses
          indegree[dependent]--;
          // If indegree becomes 0, add to queue to consider next
          if (indegree[dependent] == 0) {
            q.push(dependent);
          }
        }
      }

      // If all courses were processed, no cycle exists
      return completed == numCourses;
    }

    // Time: O(V + E) | Space: O(V + E)
    // DFS approach for cycle detection
    bool canFinish2(int numCourses, vector<vector<int>>& prerequisites) {
      // Map each course to its dependent courses
      unordered_map<int, vector<int>> m;
      for (const auto& prereq : prerequisites) {
        int course = prereq[0];
        int prerequisite = prereq[1];
        m[prerequisite].push_back(course);
      }

      // All courses along current DFS path
      unordered_set<int> visited;

      // DFS to detect cycles
      std::function<bool(int)> dfs = [&](int course) -> bool {
        if (visited.contains(course)) {
          return false;  // Cycle detected
        }
        if (!m.contains(course)) {
          return true;  // No dependencies, can complete
        }

        visited.insert(course);
        for (int nextCourse : m[course]) {
          if (!dfs(nextCourse)) {
            return false;  // Cycle detected in recursion
          }
        }
        visited.erase(course);  // Backtrack
        m.erase(course);        // Mark course as completed
        return true;
      };

      for (int i = 0; i < numCourses; ++i) {
        if (!dfs(i)) {
          return false;  // Cycle detected
        }
      }
      return true;  // All courses can be completed
    }
  };
