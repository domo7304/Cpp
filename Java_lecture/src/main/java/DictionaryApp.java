abstract class PairMap {
    protected String keyArray []; // key들을 저장하는 배열
    protected String valueArray []; // value 들을 저장하는배열
    abstract String get(String key); // key 값으로 value를 검색
    abstract void put(String key, String value); // key와 value를 쌍으로 저장
    abstract String delete(String key); // key 값을 가진 아이템(value와 함께)을 삭제. 삭제된 value 리턴
    abstract int length(); // 현재 저장된 아이템의 개수 리턴
}

class Dictionary extends PairMap {
    protected int count = 0; // 현재 저장된 아이템의 개수
    public Dictionary(int capacity) { // 생성자
        keyArray = new String [capacity];
        valueArray = new String [capacity];
    }

    @Override
    void put(String key, String value) {
        int i;
        for(i=0; i<count; i++) { // 현재 배열에 저장된 원소 개수만큼 반복, key에 해당하는 원소가 있는지 탐색
            if(keyArray[i].equals(key)) break;
        }
        if(i == count) { // key를 발견하지 못한 경우
            if(i < keyArray.length) { // 배열이 꽉차지 않은 경우에만 저장, count 값 증가
                keyArray[i] = key;
                valueArray[i] = value;
                count++;
            }
        }
        else { // key를 발견하고 value가 수정되는 경우, count는 증가시키지 않는다.
            keyArray[i] = key;
            valueArray[i] = value;
        }
    }

    @Override
    String get(String key) {
        for (int i = 0; i < count; i++){
            if (keyArray[i].equals(key)) return valueArray[i];
        }
        return null;
    }

    @Override
    String delete(String key) {
        int i;
        for (i = 0; i < count; i++){
            if (keyArray[i].equals(key)) break;
        }
        if (i == count) return null;

        String value = valueArray[i];
        for (int j = i; j < count - 1; j++){
            keyArray[j] = keyArray[j + 1];
            valueArray[j] = valueArray[j + 1];
        }
        count--;
        return value;
    }

    @Override
    int length() {
        return this.count;
    }
}

public class DictionaryApp {
    public static void main(String[] args) {
        Dictionary dic = new Dictionary(10);
        dic.put("Apple", "사과");
        dic.put("Java", "자바");
        dic.put("Eclipse", "이클립스");
        System.out.println("현재 저장된 아이템의 수는 " + dic.length());
        System.out.println("Apple의 값은 " + dic.get("Apple"));
        System.out.println("Java의 값은 " + dic.get("Java"));
        dic.delete("Java");
        System.out.println("현재 저장된 아이템의 수는 " + dic.length());
        System.out.println("Java의 값은 " + dic.get("Java"));
    }
}
