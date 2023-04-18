class DiningPhilosophersMonitor {
    private boolean[] forks = new boolean[2];

    public synchronized void pickup(int philosopherId) throws InterruptedException {
        int leftFork = philosopherId;
        int rightFork = (philosopherId + 1) % 5;
        while (forks[leftFork] || forks[rightFork]) {
            wait();
        }
        forks[leftFork] = true;
        forks[rightFork] = true;
    }

    public synchronized void putdown(int philosopherId) {
        int leftFork = philosopherId;
        int rightFork = (philosopherId + 1) % 5;
        forks[leftFork] = false;
        forks[rightFork] = false;
        notifyAll();
    }
}

class Philosopher implements Runnable {
    private int id;
    private DiningPhilosophersMonitor monitor;

    public Philosopher(int id, DiningPhilosophersMonitor monitor) {
        this.id = id;
        this.monitor = monitor;
    }

    @Override
    public void run() {
        try {
            while (true) {
                System.out.println("Philosopher " + id + " is thinking");
                Thread.sleep(1000);
                System.out.println("Philosopher " + id + " is hungry");
                monitor.pickup(id);
                System.out.println("Philosopher " + id + " is eating");
                Thread.sleep(1000);
                monitor.putdown(id);
            }
        } catch (InterruptedException e) {
        }
    }
}

public class code2 {
    public static void main(String[] args) throws InterruptedException {
        DiningPhilosophersMonitor dpMon = new DiningPhilosophersMonitor();
        Thread t1 = new Thread(new Philosopher(0, dpMon));
        Thread t2 = new Thread(new Philosopher(1, dpMon));
        Thread t3 = new Thread(new Philosopher(2, dpMon));
        Thread t4 = new Thread(new Philosopher(3, dpMon));
        Thread t5 = new Thread(new Philosopher(4, dpMon));
        t1.start();
        t2.start();
        t3.start();
        t4.start();
        t5.start();
    }
}