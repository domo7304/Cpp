import java.util.Scanner;

abstract class GameObject{
    protected int x, y; // 현재 위치(화면 맵 상의 위치)
    public GameObject(int x, int y) { // 초기 위치 설정 생성자
        this.x = x; this.y = y;
    }
    public int getX() { return x; }
    public int getY() { return y; }
    public boolean collide(GameObject p) { // 이 객체가 객체 p와 충돌했으면 true 리턴
        if(this.x == p.getX() && this.y == p.getY())
            return true;
        else
            return false;
    }
    protected abstract boolean move(); // 이동한 후의 새로운 위치로 x, y 변경, 도둑질을 했는지 리턴
    protected abstract char getShape(); // 객체의 모양을 나타내는 문자 리턴
}

class Police extends GameObject{
    private char shape;

    public Police(int x, int y) {
        super(x, y);
        this.shape = 'P';
    }

    @Override
    public boolean move(){
        int n = (int)((Math.random() * 10) % 5);

        if (n == 0 && this.y != 0) this.y--;
        else if (n == 1 && this.y != 2) this.y++;
        else if (n == 2 && this.x != 0) this.x--;
        else if (n == 3 && this.x != 2) this.x++;
        return true;
    }

    @Override
    public char getShape(){
        return this.shape;
    }
}

class Thief extends GameObject{
    private char shape;

    public Thief(int x, int y){
        super(x, y);
        this.shape = '&';
    }

    @Override
    public boolean move(){
        System.out.print("왼쪽(a), 아래(s), 위(w), 오른쪽(d), 도둑질(r) >> ");
        Scanner scanner = new Scanner(System.in);
        String command = scanner.next();

        if (command.equals("r")) {
            return true;
        }
        else {
            if (command.equals("w") && this.y != 0) this.y--;
            else if (command.equals("s") && this.y != 2) this.y++;
            else if (command.equals("a") && this.x != 0) this.x--;
            else if (command.equals("d") && this.x != 2) this.x++;
            return false;
        }
    }

    @Override
    public char getShape() { return this.shape; }
}

public class Game {
    public static void main(String[] args){
        System.out.println("이도원/컴퓨터공학과/12172169");
        System.out.println("** 도둑 잡기 게임을 시작합니다. ** \n");

        char[][] house = {{'^', '^', '^'}, {'^', '^', '^'}, {'^', '^', '^'}};
        boolean[][] state = {{false, false, false}, {false, false, false}, {false, false, false}};
        Police police = new Police(0, 0);
        Thief thief = new Thief(2, 2);

        house[police.getY()][police.getX()] = police.getShape();
        house[thief.getY()][thief.getX()] = thief.getShape();

        int cur_thief_y = thief.getY();
        int cur_thief_x = thief.getX();
        int cur_police_y = police.getY();
        int cur_police_x = police.getX();

        while(true){
            for (int i = 0; i < 3; i++){
                for (int j = 0; j < 3; j++) System.out.print(house[i][j]);
                System.out.print('\n');
            }

            if (thief.move()) {
                // 현재 위치를 도둑질 했다면, 다른 모든 집을 도둑질 했는지 확인
                state[cur_thief_y][cur_thief_x] = true;
                boolean end_flag = true;
                for (int i = 0; i < 3; i++){
                    for (int j = 0; j < 3; j++){
                        if (!state[i][j]) end_flag = false;
                    }
                }
                if (end_flag) {
                    System.out.println("당신이 이겼습니다!");
                    break;
                }
            }
            else {
                // 3x3 배열에서 위치 바꿔주기
                if (state[cur_thief_y][cur_thief_x]){
                    house[cur_thief_y][cur_thief_x] = '-';
                }
                else {
                    house[cur_thief_y][cur_thief_x] = '^';
                }
                house[thief.getY()][thief.getX()] = thief.getShape();
                cur_thief_y = thief.getY();
                cur_thief_x = thief.getX();
            }

            police.move();
            // 충돌했는지 확인
            if (thief.collide(police)){
                System.out.println("당신이 패배했습니다.");
                break;
            }

            // 3x3 배열에서 위치 바꿔주기
            if (state[cur_police_y][cur_police_x]){
                house[cur_police_y][cur_police_x] = '-';
            }
            else {
                house[cur_police_y][cur_police_x] = '^';
            }
            house[police.getY()][police.getX()] = police.getShape();
            cur_police_y = police.getY();
            cur_police_x = police.getX();
        }
    }
}