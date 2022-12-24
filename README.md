# 허리야, 펴져라! (가제)

2022학년도 2학기 어드벤처디자인 과목(아두이노) 팀프로젝트 협업을 위한 repo입니다.

- 프로젝트 기간 : 2022.11.09 - 2022.12.26 (48일간)

## 팀 소개

- 팀원 : 김민욱(202255521), 안준영(202255567), 장건호(202255597)
- 팀명 : 정컴침팬지(2조)
- 대표메일 : ahnjun0@pusan.ac.kr (안준영)

---

## Code

    ahnjun0/2022_ADV_Design
    ├ Document
    │   ├ Plan
    │   │   ├ 기자재신청목록_02조_정컴침팬지(11.18).xlsx
    │   │   └ 프로젝트 설계 발표자료 초안_02조_정컴침팬지(11.18).pptx
    │   │
    │   ├ 3DPrinter_stl // Case 3DPrinter 제작용
    │   │   ├ Body.stl
    │   │   └ Cover.stl
    │   │
    │   └ Presentation
    │
    ├ Main
    │   ├ Main_Sketch
    │   │   ├ Main_Sketch.ino // 착용하게 될 Main Arduino에 컴파일하는 Sketch file
    │   │   └ pitches.h
    │   │
    │   ├ Sub_Sketch
    │   │   └ Sub_Sketch.ino // 초음파 센서를 연결하게 될 Sub Arduino에 컴파일하는 Sketch file
    │   │
    │   ├ I2C_Scanner
    │   │   └ I2C_Scanner.ino // I2C Address 확인용
    │   │
    │   ├ Regression
    │   │   └ main.py
    │   │
    │   └ Testbed // 각종 테스트용
    │       └ Testbed.ino
    │
    └ README.md

## 기타 공지사항

- 함수 작성 시 Doxygen(@brief, @details, @param, @return 등)을 이용하여 설명합시다.
- 변수 이름은 간결하게, snake_case를 이용합시다.
- 업로드 이전, 본인 기기에서 컴파일 해서 오류가 없는지 확인하는 미덕을 갖춥시다.
