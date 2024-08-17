# FdF

`고도[,색상]` 으로 이루어진 파일 데이터를 읽어와서 3D 형태로 보여주는 지도 제작 프로젝트

![image](https://github.com/user-attachments/assets/0f881304-6c56-42cb-98b7-1f729fb12407)

## 사용 예시

- 윈도우 WSL2에서 실행하고 싶은 경우 [wiki](https://github.com/iijung/FdF/wiki) 참고

```sh
$ cd data
$ unzip maps.zip

$ cd ..
$ make
$ ./fdf data/test_maps/42.fdf
$ ./fdf data/test_maps/*.fdf
```

## 명령

| 마우스 | 설명
| --- | ---
| 좌클릭 | 이동
| 우클릭 | x,y축 회전
| 휠클릭 | z축 회전
| 스크롤 | 확대/축소

|  키보드 | 설명
| --- | ---
| `ESC` | 프로그램 종료
| `Tab` | 맵 종료
| `Enter` | 상단 뷰
| `←` | y축에서 -15도 회전
| `→` | y축에서 +15도 회전
| `↓` | x축에서 -15도 회전
| `↑` | x축에서 +15도 회전

## 테스트용 지도 생성기
- https://github.com/jgigault/42MapGenerator
