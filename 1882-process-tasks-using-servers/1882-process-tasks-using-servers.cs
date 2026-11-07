
public class Solution {
    public int[] AssignTasks(int[] servers, int[] tasks) {
        int n = servers.Length;
        int m = tasks.Length;

        int[] ans = new int[m];
        var available = new PriorityQueue<int, (int weight, int index)>();
        var busy = new PriorityQueue<int, (long freeTime, int weight, int index)>();

        for (int i = 0; i < n; i++) {
            available.Enqueue(i, (servers[i], i));
        }

        long time = 0;

        for (int i = 0; i < m; i++) {

            time = Math.Max(time, (long)i);
            while (busy.Count > 0 && busy.TryPeek(out _, out var priority) && priority.freeTime <= time) {

                int serverIndex = busy.Dequeue();

                available.Enqueue(serverIndex, (servers[serverIndex], serverIndex)
                );
            }
            if (available.Count == 0) {

                busy.TryPeek(out _, out var nextPriority);
                time = nextPriority.freeTime;
                while (busy.Count > 0 && busy.TryPeek(out _, out var priority) && priority.freeTime <= time) {

                    int serverIndex = busy.Dequeue();

                    available.Enqueue(serverIndex, (servers[serverIndex], serverIndex)
                    );
                }
            }
            int selectedServer = available.Dequeue();

            ans[i] = selectedServer;
            long freeTime = time + tasks[i];

            busy.Enqueue(selectedServer, (freeTime, servers[selectedServer], selectedServer)
            );
        }

        return ans;
    }
}
