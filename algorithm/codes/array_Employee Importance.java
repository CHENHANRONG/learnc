/*
690. Employee Importance

You are given a data structure of employee information, which includes the employee's unique id, his importance value and his direct subordinates' id.

For example, employee 1 is the leader of employee 2, and employee 2 is the leader of employee 3. They have importance value 15, 10 and 5, respectively. Then employee 1 has a data structure like [1, 15, [2]], and employee 2 has [2, 10, [3]], and employee 3 has [3, 5, []]. Note that although employee 3 is also a subordinate of employee 1, the relationship is not direct.

Now given the employee information of a company, and an employee id, you need to return the total importance value of this employee and all his subordinates.

Example 1:
Input: [[1, 5, [2, 3]], [2, 3, []], [3, 3, []]], 1
Output: 11
Explanation:
Employee 1 has importance value 5, and he has two direct subordinates: employee 2 and employee 3. They both have importance value 3. So the total importance value of employee 1 is 5 + 3 + 3 = 11.
Note:
One employee has at most one direct leader and may have several subordinates.
The maximum number of employees won't exceed 2000.

*/

/*
// Employee info
class Employee {
    // It's the unique id of each node;
    // unique id of this employee
    public int id;
    // the importance value of this employee
    public int importance;
    // the id of direct subordinates
    public List<Integer> subordinates;
};
*/



/* 
DFS solution
*/
Map<Integer, Employee> emap;
public int getImportance(List<Employee> employees, int queryid) {
    emap = new HashMap();
    for (Employee e: employees) emap.put(e.id, e);
    return dfs(queryid);
}
public int dfs(int eid) {
    Employee employee = emap.get(eid);
    int ans = employee.importance;
    for (Integer subid: employee.subordinates)
        ans += dfs(subid);
    return ans;
}



/**
use hashmap to improve fetch EE step
*/

public int getImportance(List<Employee> employees, int id) {
    int total = 0;
    Map<Integer, Employee> map = new HashMap<>();
    for (Employee employee : employees) {
        map.put(employee.id, employee);
    }
    Queue<Employee> queue = new LinkedList<>();
    queue.offer(map.get(id));
    while (!queue.isEmpty()) {
        Employee current = queue.poll();
        total += current.importance;
        for (int subordinate : current.subordinates) {
            queue.offer(map.get(subordinate));
        }
    }
    return total;
}



/*
My init solution:
use queue to store the link path.
*/
class Solution {
    public int getImportance(List<Employee> employees, int id) {
        //queue
        if(employees == null || employees.size()==0)
            return 0;
        
        int res = 0;
        Queue<Employee> eq = new LinkedList<Employee>();
        eq.add(getEmployee(employees,id));
       
        while(!eq.isEmpty()){
            Employee xm = eq.poll();
            res += xm.importance;
            for(Integer xsub : xm.subordinates){
                eq.add(getEmployee(employees, xsub));
            }
        }
        
        return res;
    }
    
    private Employee getEmployee(List<Employee> employees, int id){
        Employee res = null;
        for(Employee xstart : employees){
            if(xstart.id == id){
                res = xstart;
                break;
            }   
        }
        
        return res;
    }
}
