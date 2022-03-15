# Born2beroot 평가


# Preview
<br>

## 1. " signature.txt"에 포함된 서명이 평가할 가상 머신의 "vid"파일과 동일한지 확인 (diff 사용)

- **shasum user_name.vid > signature.txt**

<br><br>

## 2. ".vdi"파일이 어디에 있는지 물어보십시오

- 내가 만든 가상머신 폴더 안에 (goinfre 쪽)

<br><br>

## 3. 가상 머신 작동 방식

- 가상화는 PC와 같은 물리적 호스트 컴퓨터 및/또는 클라우드 공급자의 데이터 센터에 있는 서버와 같은 원격 서버에서 “빌려 온” 전용 용량의 CPU, 메모리, 스토리지를 사용하여 소프트웨어 기반 또는 “가상” 버전의 컴퓨터를 만드는 프로세스
  
-  가상 머신은 실제 컴퓨터처럼 동작하는 컴퓨터 파일(일반적으로 이미지라고 함) 
-  가상 머신은 창에서 별도의 컴퓨팅 환경으로 실행

<br><br>

## 4. 운영체제 선택

- Debian

<br><br>

## 5. Debian과 CentOS의 차이점

 - CentOS는 상용 Red Hat 리눅스 배포판의 무료 다운 스트림 재빌드
   - 패키지 포멧 RPM
   - 패키지 관리자 => YUM/DNF
 
 - Debian 다른 리눅스 배포판의 기반이 무료 업스트림 배포판
   - 패키지 포멧 DEB
   - 패키지 관리자 => dpkg/APT

<br><br>

## 6. 가상 머신의 목적

- 사용 목적
  - 하나의 컴퓨터로 서로다른 두개 이상의 운영체제를 실행하고자 할 때
  - 하나의 컴퓨터 자원을 여러 사용자에세 나누어 주는 상황에서 상호 간섭을 없애고 싶을로 때 
  - 컴퓨터의 다른 부분에 영향을 주지 않는 독립 환경을 만들고 싶을 때

<br><br>

## 7. Debian인 경우 apt와 aptitude의 차이점 그리고 APPArmor에 대하여

## SELinux

- Secutity-Enhaced Linux

- 미국 국방부 스타일의 강제 접근 제어 (MAC)를 포함한 접근 제어 보안 정책을 지원하는 매커니즘을 제공하는 리눅스 커널 보안 모듈

- 다양한 리눅스 배포판에 추가할 수 있는 커널 수정 및 사용자 공간 도구들의 모임

- 레드햇 계열(RHEL, Fedora, CentOS)

- MAC 적용 (전통적인 Linux는 DAC)

- 시스템 전체에 보안 설정

<br>

## AppArmor

- Application Armor

- 시스템 관리자가 프로그램 프로필 별로 프로그램의 역량을 제한할 수 있게 해주는 리눅스 커널 보안 모듈

- SUSE 계열 (SUSE Linux), 데비안 계열 (Debian, Ubuntu)

- MAC 적용 (전통적인 Linux는 DAC)

- 개별 응용 프로그램을 보호하는 일에 집중

- 응용 프로그램 단위의 보안 모델 구현

- AppArmor는 SELinux를 대체하는 한 부분으로서 제공

<br>

### 접근 제어 모델이란?
<br>

> 프레임워크로 주체가 어떨게 객체에 접근하는 지 설명하는 모델

* 주체의 객체 사용데 대한 엄격한 정의를 내리게 된다.

- 주체가 객체에 접근하려는 접근 시도가 생성되면 이를 허용할 것인지를 결쩡하기 위해 접근통제 모델을 이용


<br>

### 강제적 접근 통제 (MAC)

- Mandatory Access Control

- 보안 레이블과 보안 허가증을 비교하여 접근 제어

> 보안 레이블 : 특정 시스템 자원이 얼마나 중요한 자원인지를 나타내는 정보

> 보안 허가증 : 어떤 시스템 객체가 특정 자원에 접근할 수 있는지를 나타내는 정보

- 비밀서를 갖는 객체에 대하여 주체가 갖는 권한에 근거하여 객체에 대한 접근을 제어하는 방법

- 사용자의 의도와는 관계없이 의무적으로 접근을 제어하는 규칙 기반 접근 통제
- 장점
	* 보안성 우수

	* 중앙 집중식 관리 형태라 모든 객체에 대한 관리가 용이

- 단점
	* 모든 접근에 대해 레이블링의 정의하고 보안 정책을 확인해야 하므로 성능 저하 방생
	* 주로 군 시스템에 사용되며 상업적인 분야에서는 적용하기 어렵다

<br>

### 임의적 접근 통제 (DAC)

- Discretionary Access Control

- 접근을 요청하는 자의 신원, 그리고 어떤 사람이 접근 승인이 되는 지를 나타내는 접근 규칙에 기반을 두는 접근 제어

- 한 개체가 자신의 의지로 다른 개체가 어떤 자원에 접근이 가능하도록 승인해주는 접근 권한을 가질수 있다

- 주체가 속해있는 그룹의 신원에 근거하여 객체에 대한 접근을 제한하는 방법으로 객체의 소유자가 접근 여부를 결정

- 분산형 보안관리 형태
	* 신원 기반 접근 통제
	* 사용자 기반 통제
	* 혼합 방식 접근 통제

- 임의적 접근 통제 : 일반적으로 ACL을 통해서 구현

- 통제의 기준이 주체의 신분에 근거를 두고 있으며 접근 통제 매커니즘이 데이터의 의미에 대해 아무 지식을 가지고 있지 않다

- 단점
	* 신분이 중요한 정보이기 때문에 다른 사람의 신분을 이용해서 불법적으로 접근할 수 있다
	* 중앙집중형 관리 방식인 강제적 접근 통제 모델보다 관이가 용이하지 않다

## apt & aptitude

###  Apt 란?

> Apt => Advanced Package Tool 시스템에 포함된 핵심 도구들의 집합

- Apt로 처리 할 수 있는 작업
  - 응용프로그램 설치
  - 응용프로그램 삭제
  - 응용프로그램을 항상 최신버전으로 유지
  - 등등....

### dpkg 란?

> dpkg => 데비안 패키지 관리 시스템의 기초가 되는 소프트웨어

- deb패키지(확장자가 .deb로 끝나는 파일)의 설치, 삭제를 위해 사용

### aptitude

- dpkg와 apt의 경우 제대로 사용하기 위해서는 좀 더 많은 지식을 요구한다. 그에 비하여 aptitude의 경우 주요 패키지 작업 과정을 자동화하여 가능한 쉽게 작업할 수 있도록 해주므로 보다 쉽게 할 수 있다.

- aptitude는 사용하지 않는 패키지를 자동적으로 제거해준다. 반면, apt는 추가적 옵션 필요
  
- aptitude는 why와 why-not커맨드를 통해 특정 패키지를 설치할 때 어떤 것이 요구되고, 어떤 것과 충돌하는지 확인할 수 있다.
  
- aptitude는 설치, 제거, 업데이트 과정에서 충돌이 있는 경우 다른 대안을 제시해 준다.(apt는 그냥 안된다고 함)

<br><br>

# Simple Setup

## 8. UFW 서비스가 시작되었는 지 확인

- **sudo ufw status verbose**

<br><br>

## 9. SSH 서비스가 시작 되었는 지 확인

- **apt search openssh-server** [openssh 설치 여부 확인]

- **systemctl status ssh** [openssh 실행 여부와 사용 포트 확인]

<br><br>

## 10. 선택한 운영체제가 Debian 또는 CentOS인지 확인

- **uname -srvmo**

<br><br>

#  User Part


## 11. user가 sudo와 user42그룹에 포함되어 있는 지 확인 

- **id user_name**

<br><br>

## 12. 비밀번호 정책과 관련하여 주제에 부과 된 규칙이 적용되었는지 확인

- 먼저 새 사용자를 만듭니다. 주제 규칙에 따라 원하는 비밀번호를 지정하십시오.

- [**useradd user_name**] [**passwd user_name**]

<br><br>

## 13. subject에서 요구한 규칙을 어떻게 설정할 수 있었는지 설명

- **sudo vi /etc/login.defs** : default password details

  - `PASS_MAX_DAYS` 30 
  -  `PASS_MIN_DAY` 2
  -   `PASS_WARN_AGE` 7
  -    `PASS_MIN_LEN` 10

1. Your password has to expire every 30 days. // password 는 30일 마다 만료

    `PASS_MAX_DAYS 30`

2. The minimum number of days allowed before the modification of a password will be set to 2. // 비밀번호 최소 사용일이 2일

    `PASS_MIN_DAY 2`

3. The user has to receive a warning message 7 days before their password expires. // 유저는 비밀번호 만료 7일 전에 경고 메세지를 받아야 함

    `PASS_WARN_AGE 7`

4. Your password must be at least 10 characters long. It must contain an uppercase letter and a number. Also, it must not contain more than 3 consecutive identical characters. // 비밀번호는 최소 10자리여야 한다. 영어 대문자 + 숫자는 반드시 포함해야 함. 3개 이상의 연속된 동일한 문자를 가지면 안된다

    `PASS_MIN_LEN 10` , `ucredit=-1` (대문자), `dcredit=-1` (숫자), `maxrepeat=3`

5. The password must not include the name of the user. // 비밀번호는 사용자의 이름을 포함하면 안된다

    `reject_username`

6. The password must have at least 7 characters that are not part of the former password.// 비밀번호는 이전 비밀번호와 다른 최소 7글자를 가져야 한다.

    `difok=7`

7. Of course, your root password has to comply with this policy. // root password는 이 정책을 따라야 한다.

    `enforce_for_root` (사용자가 패스워드를 바꾸려고 하는 경우에도 위의 조건들 적용)

<br><br>

# Hostname and partitions

## 14. 가상머신의 호스트 이름이 다름과 같이 올바르게 포맷 되었는 지 확인 

- longin42 (**hostnamectl** 명령어로 확인)

- 호스트 이름 수정 명령어
  - **sudo hostnamectl set-hostname NAME**

<br><br>

## 15. 가상머신의 파티션을 보는 방법을 보여주어야 한다

- **lsblk**

<br><br>

## 16. LVM이 작동하는 방식과 그에 대한 모든 것에 대한 간략한 설명 제공

- 기존에는 파일시스템이 블록 장치에 직접 접근해서 읽고/쓰기를 했다면 LVM을 사용하면 **파일 시스템이 LVM이 만든 가상의 블록 장치에 읽고/쓰기**를하게 된다.

- **LVM은 물리적 스토리지 이상의 추상적 레이어를 생성해서 논리적 스토리지(가상의 블록 장치)를 생성할 수 있게 해준다.** 직접적으로 물리적 스토리지를 사용하는 것보다 다양한 측면에서 유연성을 제공한다.

<br><br>

# SUDO

## 17. 가상 머신에 "sudo" 프로그램이 제대로 설치 되었는 지 확인

- **dpkg -l sudo**

<br><br>

## 18. "sudo" 그룹에 새 사용자를 할당하는 것을 보여준다

- **usermod -aG sudo user_name**

<br><br>

## 19. 당신은 적절한 예시를 통해 sudo의 가치와 작동 방식을 설명해야함

- 유닉스 및 유닉스 계열 운영체제에서, 다른 사용자의 보안 권한, 보통 슈퍼유저로서 프로그램을 구동할 수 있도록 하는 프로그램
  
  - 관리자의 권한을 빌릴때 사용
  
> "Substitute user do" (다른 사용자의 권한으로 실행)의 줄임말

### sudoer 파일

  - sudo 명령어를 사용할 수 있는 계정을 관리하는 설정 파일
  - /etc 폴더에 존재

<br><br>

## 20. subject에서 부과 한 규칙의 구현을 보여주어야 함


- "/ var / log / sudo /" 폴더가 있고 하나 이상의 파일이 있는지 확인합니다.

- 이 폴더에있는 파일의 내용을 확인하십시오. sudo와 함께 사용 된 명령의 기록을 볼 수 있습니다. **cd /var/log/sudo/**
- 마지막으로 sudo를 통해 명령을 실행 해보십시오. 
"/ var / log / sudo /"폴더의 파일이 업데이트되었는지 확인합니다. 
**sudo systemctl restart ssh** &&  **cd/var/log/sudo**

~~~shell
Defaults    authfail_message="Authentication attempt failed."
Defaults    badpass_message="Wrong password!"
Defaults    log_input
Defaults    log_output
Defaults    requiretty
Defaults    iolog_dir="/var/log/sudo/"
~~~

- authfail_message="메세지" : 권한 획득 실패시 띄울 커스텀 메시지
- badpass_message="메시지" : 암호 실패시 띄울 메시지
- log_input : sudo를 통해 입력된 input은 로그에 기록된다.
- log_output : sudo를 통해 입력된 output은 로그에 기록된다.
- requiretty : tty에 연결되지 않은 채로 sudo를 실행하는 것을 금지? ex. 쉘 스크립트 상에서 sudo 커맨드 수행 금지.
- iolog_dir="경로" : 로그를 저장할 경로.
  
<br><br>

# UFW

## 21. 가상머신에 "UFW" 프로그램이 제대로 설치되었는 지 확인합니다

- **sudo ufw version**

<br><br>

## 22. 제대로 작동하는 지 확인 하십시오

- **sudo ufw status**

<br><br>

## 23. UFW가 무엇인지, 그리고 그것을 사용하는 가치에 대하여 설명해야한다.

> 미리 정의된 보안 규칙에 기반한, 들어오고 나가는 네트워크 트래픽을 모니터링하고 제어하는 네트워크 보안 시스템

- 일반적으로 신뢰할 수 있는 내부 네트워크, 신뢰할 수 없는 외부 네트워크간의 장벽을 구성
- 서로 다른 네트워크를 지나는 데이터를 허용하거나 거부하거나 검열, 수정하는 하드웨어나 소프트웨어 장치 

<br><br>

## 24. UFW의 활성 규칙을 나열합니다. 포트 4242에 대한 규칙이 있어야합니다.

- **sudo ufw status numbered**

<br><br>

## 25. 새 규칙을 추가하여 파트 8080을여십시오. 활성 규칙을 나열하여 이 규칙이 추가되었는지 확인하십시오.

- **sudo ufw allow 8080**

- **sudo ufw status numbered**

<br><br>

## 26. 마지막으로 평가된 학생의 도움을 받아서 새규칙을 삭제합니다.

- **sudo ufw delete 규칙번호**

<br><br>

# SSH

## 27. 가상 머신에 SSH 서비스가 제대로 설치되어 있는지 확인합니다

- **apt search openssh-server**

<br><br>

## 28. SSH가 무엇인지, 그리고 그 사용의 가치를 설명 할 수 있어야한다.

> SSH (Secure Shell) 보안을 중요시한 프로토콜


- 원격 터미널 접속은 왜 필요할까?

  - 다양한 원격 접속 프로그램을 사용 원격지에 있는 서버에 굳이 찾아가지 않고 해당 서버의 주소만 알고 있다면 다른 pc를 통하여 바로 접속
  

- 안전하지 않은 기존의 TCP 연결을 안전한 SSH로 변환하는 과정

- 용도
  - 사용자 및 자동화된 프로세스에 대한 보안 엑세스 제공
  
  - 파일 전송 기능
  - 원격 명령 실행
  - 네트워크 인프라 및 기타 시스템 구성 요소 관리

<br><br>

## 29. SSH 서비스가 포트 4242 만 사용하는지 확인합니다.

- **systemctl status ssh**

<br><br>

## 30. 물론 주제에 명시된대로 "루트"사용자로 SSH를 사용할 수 없는지 확인해야합니다. 

- **ssh -p 4242 root@192.168.56.1** ⇒ permission denied

<br><br>

## 31. "Cron" 이란?

- cron은 shell 명령어들이 주어진 일정에 주기적으로 실행하도록 규정해 놓은 crontab(cron table) 파일에 의해 구동된다