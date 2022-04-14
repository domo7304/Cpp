interface Device {
    void on();
    void watch();
    void off();
}
public class TVimpl implements Device {

    public void on() {
        System.out.println("켜졌습니다.");
    }

    public void watch() {
        System.out.println("방송중입니다.");
    }

    public void off() {
        System.out.println("종료합니다.");
    }

    public static void main(String [] args) {
        TVimpl myTV = new TVimpl();
        myTV.on();
        myTV.watch();
        myTV.off();
    }
}