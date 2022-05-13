package week10;

import java.util.HashMap;
import java.util.Scanner;

class Location{
    private double longitude;
    private double latitude;

    public Location(double longitude, double latitude){
        this.longitude = longitude;
        this.latitude = latitude;
    }

    public void setLocation(double longitude, double latitude){
        this.longitude = longitude;
        this.latitude = latitude;
    }
    public double getLongitude() { return longitude; }
    public double getLatitude() { return latitude; }
}

public class LocationMap {
    public static void main(String[] args) {
        HashMap<String, Location> hs = new HashMap<>();
        Scanner scanner = new Scanner(System.in);

        while(true){
            System.out.print("저장할 도시의 이름과 위도, 경도를 입력해주세요.('종료' 입력 시 종료됩니다) \n>> ");
            String name = scanner.next();
            if (name.equals("종료")) break;

            double longitude = scanner.nextDouble();
            double latitude = scanner.nextDouble();
            Location location = new Location(longitude, latitude);
            hs.put(name, location);
        }

        while(true){
            System.out.print("위도와 경도를 얻어올 도시의 이름을 입력해주세요.('종료'입력 시 종료됩니다.) \n>> ");
            String name = scanner.next();
            if (name.equals("종료")) {
                System.out.println("프로그램이 종료됩니다.");
                break;
            }
            if (name == null) System.out.println(name + " 은 존재하지 않습니다.");
            System.out.println(name + " 의 경도와 위도는 다음과 같습니다. 경도 : " + hs.get(name).getLongitude()
                                + ", 위도 : " + hs.get(name).getLatitude());
        }
    }
}
