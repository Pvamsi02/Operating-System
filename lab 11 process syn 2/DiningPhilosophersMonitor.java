// import java.util.concurrent.locks.Condition;
// import java.util.concurrent.locks.Lock;
// import java.util.concurrent.locks.ReentrantLock;

// class Chopstick {
//     private boolean availability;

//     public Chopstick() {
//         availability = true;
//     }

//     public boolean getAvailability() {
//         return availability;
//     }

//     public void setAvailability(boolean flag) {
//         availability = flag;
//     }
// }

// class Helper {
//     private Lock mutex = null;
//     private Condition[] cond;
//     private String[] state;
//     private int[] id;

//     private void outputState(int id) {
//         StringBuffer line = new StringBuffer();
//         for (int i = 0; i < 5; i++)
//             line.append(state[i] + " ");
//         System.out.println(line + "(" + (id + 1) + ")");
//     }

//     public Helper() {
//         id = new int[5];
//         mutex = new ReentrantLock();
//         state = new String[5];

//         cond = new Condition[5];
//         for (int i = 0; i < 5; i++) {
//             id[i] = i;
//             state[i] = "O";
//             cond[i] = mutex.newCondition();
//         }
//     }

//     public void setState(int id, String s) {
//         state[id] = s;
//     }

//     public void grabChopsticks(int id, Chopstick l, Chopstick r) {
//         mutex.lock();
//         try {
//             setState(id, "o");
//             while (!l.getAvailability() || !r.getAvailability())
//                 cond[id].await();
//             l.setAvailability(false);
//             r.setAvailability(false);
//             setState(id, "X");
//             outputState(id);
//         } catch (InterruptedException e) {
//             e.printStackTrace();
//         } finally {
//             mutex.unlock();
//         }
//     }

//     public void releaseChopsticks(int id, Chopstick l, Chopstick r) {
//         mutex.lock();
//         try {
//             setState(id, "O");
//             l.setAvailability(true);
//             r.setAvailability(true);
//             cond[(id + 1) % 5].signalAll();
//             cond[(id + 4) % 5].signalAll();
//             outputState(id);
//         } finally {
//             mutex.unlock();
//         }
//     }
// }

// class Philosopher implements Runnable {
//     private Helper hlp;
//     private Chopstick l, r;
//     private int id;

//     public Philosopher(int id, Chopstick l, Chopstick r, Helper i) {
//         this.hlp = i;
//         this.l = l;
//         this.r = r;
//         this.id = id;
//     }

//     private void eat() {
//         try {
//             Thread.sleep(2000);
//         } catch (InterruptedException e) {
//         }
//     }

//     private void think() {
//         try {
//             Thread.sleep(2000);
//         } catch (InterruptedException e) {
//         }
//     }

//     public void run() {
//         while (true) {
//             hlp.grabChopsticks(id, l, r);
//             eat();
//             hlp.releaseChopsticks(id, l, r);
//             think();
//         }
//     }
// }

// public class dinningPhilosopherMonitor {
//     private Chopstick[] s;
//     private Philosopher[] f;
//     private Helper hlp;

//     private void init() {
//         s = new Chopstick[5];
//         f = new Philosopher[5];
//         hlp = new Helper();
//         for (int i = 0; i < 5; i++)
//             s[i] = new Chopstick();
//         for (int i = 0; i < 5; i++) {
//             f[i] = new Philosopher(i, s[i], s[(i + 4) % 5], hlp);
//             new Thread(f[i]).start();
//         }
//     }

//     public dinningPhilosopherMonitor() {
//         init();
//     }

class DiningPhilosophersMonitor {

    public static int i;

    public static void main(String[] args) {

        Fork[] fork = new Fork[5];

        for (i = 0; i < fork.length; i++) {
            fork[i] = new Fork("Fork " + (i + 1));
        }

        Philosopher[] phil = new Philosopher[5];

        phil[0] = new Philosopher("Philosopher 1:- ", fork[0], fork[4]);
        phil[1] = new Philosopher("Philosopher 2:- ", fork[1], fork[0]);
        phil[2] = new Philosopher("Philosopher 3:- ", fork[2], fork[1]);
        phil[3] = new Philosopher("Philosopher 4:- ", fork[3], fork[2]);
        phil[4] = new Philosopher("Philosopher 5:- ", fork[4], fork[3]);

        for (i = 0; i < phil.length; i++) {
            System.out.println("Philosopher " + (i + 1) + " enters..");
            Thread thread = new Thread(phil[i]);
            thread.start();
        }
    }
}

class Philosopher extends Thread {
    private Fork l_fork, r_fork;
    private String phil_name;
    private int s = 1;

    public Philosopher(String s, Fork l_fork, Fork r_fork) {
        this.phil_name = s;
        this.l_fork = l_fork;
        this.r_fork = r_fork;
    }

    public void consume() {
        if (l_fork.f_s == 1) {
            if (r_fork.f_s == 1) {
                l_fork.wait(phil_name, "Left");
                r_fork.wait(phil_name, "Right");
                System.out.println(phil_name + " Eating..");
                r_fork.signal(phil_name, "Right");
                l_fork.signal(phil_name, "Left");
                think(phil_name);
            } else {

                // System.out.println("inin");
                System.out.println(phil_name + " Waiting for right " + r_fork.f_name + "..");
                l_fork.signal(phil_name, "Left");
                    try {
                    Thread.sleep(3000);
                } catch (Exception e) {
                    System.out.println("Some error");
                }
                think(phil_name);

            }
        } else {
            // System.out.println("in");
            System.out.println(phil_name + " Waiting for left " + l_fork.f_name + "..");
            think(phil_name);
        }
    }

    public void think(String s) {
        System.out.println(s + " Thinking..");
        try {
            Thread.sleep(3000);
        } catch (Exception e) {
            System.out.println("Some error");
        }
    }

    @Override
    public void run() {
        consume();
    }
}

class Fork {
    public String f_name;
    public int f_s = 1;

    public Fork(String s) {
        this.f_name = s;
        this.f_s = 1;
    }

    public synchronized void wait(String phil_name, String side) {
        System.out.println(phil_name + " Using " + f_name + " as " + side + " fork..");
        this.f_s = 0;
    }

    public synchronized void signal(String phil_name, String side) {
        System.out.println(phil_name + " Releasing " + f_name + " as " + side + " fork..");
        this.f_s = 1;
    }

}
