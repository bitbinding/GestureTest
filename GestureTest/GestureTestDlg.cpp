
// GestureTestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "GestureTest.h"
#include "GestureTestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CGestureTestDlg 对话框




CGestureTestDlg::CGestureTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGestureTestDlg::IDD, pParent)
	, m_e13(235)
	, m_e21(14339327)//11455228
	, m_e22(10)//60
	, m_e23(0)//1
	, m_erhsl(2.0f)
	, m_erhbj(1)
	, m_c1(FALSE)	
	, m_c2(TRUE)	
	, m_r1(0)	
	, m_e01(0)
	, m_e02(640)
	, m_e03(480)
	, m_c0(TRUE)
	, m_ea1(0.225)
	, m_ctop(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_Video=NULL;
	m_Captured=NULL;
	m_Frame=NULL;//用于存储一帧
	m_GrabFrame=NULL;//用于存储一帧
	m_temp=NULL;
	pDC=NULL;
	hDC=NULL;
	pwnd=NULL;	
	smoothMode=0;
	m_e11 = 7;
	m_e12 = 60;
	m_FrameCreated=false;
	centx=0;
	centy=0;
	zone=0;
	screenPaintMode=false;
	pWinDC=NULL;
	pen=NULL;
	posleng=0;
	screenwid=640;
	screenhei=480;
	mouseClickMode=false;
	size=0;
	sizeprev=0;
	camMouseIsDown=false;
	//  m_r1 = 0;
}

void CGestureTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT1, m_e11);
	//  DDX_Text(pDX, IDC_EDIT2, m_e12);
	DDX_Text(pDX, IDC_EDIT1, m_e11);
	//DDV_MinMaxInt(pDX, m_e11, 0, 7);
	DDX_Text(pDX, IDC_EDIT2, m_e12);
	//DDV_MinMaxInt(pDX, m_e12, -255, 255);
	//  DDX_Radio(pDX, IDC_RADIO1, m_r1);
	//  DDX_Radio(pDX, IDC_RADIO1, m_r1);
	//  DDX_Text(pDX, IDC_EDIT3, m_e21);
	//  DDX_Control(pDX, IDC_EDIT2, m_e13);
	DDX_Text(pDX, IDC_EDIT3, m_e13);
	DDX_Text(pDX, IDC_EDIT4, m_e21);
	DDX_Text(pDX, IDC_EDIT5, m_e22);
	DDX_Text(pDX, IDC_EDIT6, m_e23);
	//  DDX_Control(pDX, IDC_EDIT7, m_erhsl);
	//  DDX_Text(pDX, IDC_EDIT7, m_erhsl);
	DDX_Text(pDX, IDC_EDIT8, m_erhbj);
	DDX_Check(pDX, IDC_CHECK1, m_c1);
	DDX_Text(pDX, IDC_EDIT7, m_erhsl);
	DDX_Check(pDX, IDC_CHECK2, m_c2);
	//  DDX_Text(pDX, IDC_EDIT9, m_e31);
	//  DDX_Text(pDX, IDC_EDIT10, m_e32);
	//  DDX_Control(pDX, IDC_RADIO1, m_r1);
	DDX_Radio(pDX, IDC_RADIO1, m_r1);
	//  DDX_Text(pDX, IDC_EDIT11, m_e01);
	//  DDX_Text(pDX, IDC_EDIT12, m_e02);
	//  DDX_Control(pDX, IDC_EDIT13, m_e03);
	DDX_Text(pDX, IDC_EDIT11, m_e01);
	DDX_Text(pDX, IDC_EDIT12, m_e02);
	DDX_Text(pDX, IDC_EDIT13, m_e03);
	DDX_Check(pDX, IDC_CHECK3, m_c0);
	DDX_Text(pDX, IDC_EDIT10, m_ea1);
	DDX_Check(pDX, IDC_CHECK4, m_ctop);
}

BEGIN_MESSAGE_MAP(CGestureTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_BN_CLICKED(IDOK, &CGestureTestDlg::OnBnClickedOk)
ON_WM_TIMER()
ON_BN_CLICKED(IDC_BUTTON1, &CGestureTestDlg::OnBnClickedButton1)
ON_BN_CLICKED(IDC_BUTTON2, &CGestureTestDlg::OnBnClickedButton2)
ON_BN_CLICKED(IDC_BUTTON3, &CGestureTestDlg::OnBnClickedButton3)
ON_BN_CLICKED(IDC_BUTTON4, &CGestureTestDlg::OnBnClickedButton4)
ON_STN_CLICKED(IDC_STATIC1, &CGestureTestDlg::OnClickedStatic1)
ON_WM_CTLCOLOR()
ON_BN_CLICKED(IDC_RADIO3, &CGestureTestDlg::OnBnClickedRadio3)
ON_EN_CHANGE(IDC_EDIT13, &CGestureTestDlg::OnEnChangeEdit13)
ON_EN_CHANGE(IDC_EDIT12, &CGestureTestDlg::OnEnChangeEdit12)
ON_EN_CHANGE(IDC_EDIT11, &CGestureTestDlg::OnEnChangeEdit11)
ON_BN_CLICKED(IDC_BUTTON5, &CGestureTestDlg::OnBnClickedButton5)
ON_BN_CLICKED(IDC_BUTTON6, &CGestureTestDlg::OnBnClickedButton6)
ON_EN_SETFOCUS(IDC_EDIT12, &CGestureTestDlg::OnSetfocusPictureWid)
ON_EN_KILLFOCUS(IDC_EDIT12, &CGestureTestDlg::OnKillfocusPictureWid)
ON_EN_SETFOCUS(IDC_EDIT13, &CGestureTestDlg::OnSetfocusPictureHei)
ON_EN_KILLFOCUS(IDC_EDIT13, &CGestureTestDlg::OnKillfocusPictureHei)
END_MESSAGE_MAP()


// CGestureTestDlg 消息处理程序

BOOL CGestureTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	pwnd = GetDlgItem(IDC_STATIC1);
	pDC =pwnd->GetDC();
	hDC= pDC->GetSafeHdc();
	pwnd->GetClientRect(&rect);
	if (hDC==NULL)
	{
		MessageBox("无法获取hdc");
		return TRUE;
	}
	if (m_Video==NULL)
	{
		m_Video=cvCreateCameraCapture(m_e01);
	}
	if (m_Video==NULL)
	{
		MessageBox("无法打开摄像头");
		return TRUE;
	}	
	
	Invalidate(TRUE);
	UpdateWindow();
	screenwid=GetSystemMetrics(SM_CXSCREEN);
	screenhei=GetSystemMetrics(SM_CYSCREEN);
	SetTimer(1,100,NULL);
	MoveControls(m_e02,m_e03);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CGestureTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CGestureTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CGestureTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void blurFixFilter(IplImage *memopic,IplImage *temppic,int bll,int blh){
	//模糊后修正滤镜（修正的目标图像（模糊前图像），模糊后图像，低阈值保留，高阈值保留
	if(bll==0){
		cvCopy(temppic,memopic);
		return;
	}
	int hei    = memopic->height;
	int wid     = memopic->width;
	int step      = memopic->widthStep;
	int channels  = memopic->nChannels;
	int hs=hei*step;
	int wc=wid*channels;
	uchar* src = (uchar *)memopic->imageData;
	uchar* dest = (uchar *)temppic->imageData;
	uchar* mByte = src;
	uchar* pByte = dest;
	int colour=0;
	int i=0,j=0,k=0;	
	int colourmax=0;//最大色差	
	for(j=0;j<hs;j+=step) {
		for(i=0;i<wc;i+=channels) {
			mByte=src+i+j;
			pByte=dest+i+j;			
			colourmax=pByte[0]>mByte[0]?pByte[0]-mByte[0]:mByte[0]-pByte[0];
			colour=pByte[1]>mByte[1]?pByte[1]-mByte[1]:mByte[1]-pByte[1];
			colourmax=colourmax<colour?colour:colourmax;
			colour=pByte[2]>mByte[2]?pByte[2]-mByte[2]:mByte[2]-pByte[2];
			colourmax=colourmax<colour?colour:colourmax;
				
			if(colourmax>=bll){
				mByte[0]=(mByte[0]-pByte[0])*bll/colourmax+pByte[0];
				mByte[1]=(mByte[1]-pByte[1])*bll/colourmax+pByte[1];
				mByte[2]=(mByte[2]-pByte[2])*bll/colourmax+pByte[2];
			}
			colourmax=pByte[0]>mByte[0]?pByte[0]-mByte[0]:mByte[0]-pByte[0];
			colour=pByte[1]>mByte[1]?pByte[1]-mByte[1]:mByte[1]-pByte[1];
			colourmax=colourmax<colour?colour:colourmax;
			colour=pByte[2]>mByte[2]?pByte[2]-mByte[2]:mByte[2]-pByte[2];
			colourmax=colourmax<colour?colour:colourmax;
			if(colourmax<255-blh && blh<255){
				mByte[0]=(mByte[0]-pByte[0])*colourmax/(255-blh)+pByte[0];
				mByte[1]=(mByte[1]-pByte[1])*colourmax/(255-blh)+pByte[1];
				mByte[2]=(mByte[2]-pByte[2])*colourmax/(255-blh)+pByte[2];
			}
		}
	}
}

void ruihuaFilter(const IplImage *memopic,IplImage *temppic,float sl,int r,int yz){
	//锐化滤镜（锐化前图像，锐化后图像，数量，半径,阈值）
	int hei    = memopic->height;
	int wid     = memopic->width;
	int step      = memopic->widthStep;
	int channels  = memopic->nChannels;
	int hs=hei*step;
	int wc=wid*channels;
	uchar* src = (uchar *)memopic->imageData;
	uchar* dest = (uchar *)temppic->imageData;
	uchar* mByte = src;
	uchar* pByte = dest;
	int i=0,j=0,k=0,l=0,m=0,n=0;	
	int leng=r*2+1;//锐化求平均时所用方框的边长	
	int colour;//转换的中间变量
	int er,eg,eb;//r,g,b的平均值
	int nr,ng,nb;//r,g,b锐化后的值（未考虑阈值和柔化）
	cvSmooth(memopic,temppic,CV_GAUSSIAN,leng,leng);
	for(j=0;j<hs;j+=step) {
		for(i=0;i<wc;i+=channels) {
			mByte=src+i+j;
			pByte=dest+i+j;
			er=pByte[2];
			eg=pByte[1];
			eb=pByte[0];
			nb=(int)((*mByte-eb)*sl+eb);
			if(nb<0){nb=0;}
			else if(nb>255){nb=255;}
			ng=(int)((mByte[1]-eg)*sl+eg);
			if(ng<0){ng=0;}
			else if(ng>255){ng=255;}
			nr=(int)((mByte[2]-er)*sl+er);
			if(nr<0){nr=0;}
			else if(nr>255){nr=255;}
			if(yz==0 || abs(nb-*mByte)>=yz || abs(ng-*(mByte+1))>=yz || abs(nr-*(mByte+2))>=yz){				
				*pByte=nb;
				*pByte++;
				*pByte=ng;
				*pByte++;
				*pByte=nr;
			}else{
				colour=(nb-*mByte)*abs(*mByte-nb)/yz+*mByte;
				if(colour<=0) {*pByte=0;}
				else if(colour>=255) {*pByte=255;}
				else {*pByte=colour;}
				pByte++;
				mByte++;

				colour=(ng-*mByte)*abs(*mByte-ng)/yz+*mByte;
				if(colour<=0) {*pByte=0;}
				else if(colour>=255) {*pByte=255;}
				else {*pByte=colour;}
				pByte++;
				mByte++;

				colour=(nr-*mByte)*abs(*mByte-nr)/yz+*mByte;
				if(colour<=0) {*pByte=0;}
				else if(colour>=255) {*pByte=255;}
				else {*pByte=colour;}
			}
		}
	}
}

void colourSelect(IplImage *memopic,IplImage *temppic,int seedColour,int seedCapacity,int spread=0,bool colourMode=true,bool labMode=false){
	//按种子颜色选取
	int hei    = memopic->height;
	int wid     = memopic->width;
	int step      = memopic->widthStep;
	int channels  = memopic->nChannels;
	int hs=hei*step;
	int wc=wid*channels;
	uchar* src = (uchar *)memopic->imageData;
	uchar* dest = (uchar *)temppic->imageData;
	uchar* mByte = src;
	uchar* pByte = dest;
	int i=0,j=0;
	int colour=0;
	int colourmax=0;
	uchar* mByte1=src;
	uchar* pByte1=dest;
	uchar r,g,b;
	int count;
	r=(uchar)(seedColour&0xff);
	g=(uchar)(seedColour>>8&0xff);
	b=(uchar)(seedColour>>8&0xff);
	double yt,ut,vt;

	if(colourMode){
		if(labMode){
			static CvSize pointSize;
			pointSize.width=1;
			pointSize.height=1;
			static IplImage *rgb0=cvCreateImage(pointSize,memopic->depth, memopic->nChannels);
			static IplImage *rgbt=cvCreateImage(pointSize,memopic->depth, memopic->nChannels);
			(rgb0->imageData)[0]=b;
			(rgb0->imageData)[1]=g;
			(rgb0->imageData)[2]=r;
			cvCvtColor(rgb0,rgbt,CV_BGR2Lab);
			r=(rgbt->imageData)[2];
			g=(rgbt->imageData)[1];
			cvCvtColor(memopic,temppic,CV_BGR2Lab);
		}else{
			yt=0.299*r + 0.587*g + 0.114*b;
			ut=0.436*(b-yt)/(1-0.114)+128;
			vt=0.615*(r-yt)/(1-0.299)+128;
			r=(uchar)(int)ut;
			g=(uchar)(int)vt;					
			for(j=0;j<hs-step;j+=step) {
				for(i=0;i<wc-channels;i+=channels) {
					mByte=src+i+j;
					pByte=dest+i+j;
					yt=0.299*mByte[2] + 0.587*mByte[1] + 0.114*mByte[0];
					ut=0.436*(mByte[0]-yt)/(1-0.114)+128;
					vt=0.615*(mByte[2]-yt)/(1-0.299)+128;				
					pByte[2]=(uchar)(int)ut;
					pByte[1]=(uchar)(int)vt;
					//pByte[0]=(uchar)(int)ut;
				}
			}
		}
	}	
	for(j=0;j<hs-step;j+=step) {
		for(i=0;i<wc-channels;i+=channels) {
			mByte=src+i+j;
			pByte=dest+i+j;
			if(colourMode){
				colourmax=r>pByte[2]?r-pByte[2]:pByte[2]-r;
				colour=g>pByte[1]?g-pByte[1]:pByte[1]-g;				
				colourmax=colourmax<colour?colour:colourmax;
			}else{
				colourmax=b>mByte[0]?b-mByte[0]:mByte[0]-b;
				colour=g>mByte[1]?g-mByte[1]:mByte[1]-g;
				colourmax=colourmax<colour?colour:colourmax;
				colour=r>mByte[2]?r-mByte[2]:mByte[2]-r;
				colourmax=colourmax<colour?colour:colourmax;
			}
			if(colourmax<=seedCapacity){
				pByte[0]=255;
			}else{
				pByte[0]=0;
			}
		}
	}
	if(spread>0 && wid>=10 && hei>=10){
		do{
			count=0;
			for(j=0;j<hs-step;j+=step) {
				for(i=0;i<wc-channels;i+=channels) {
					mByte=src+i+j;
					pByte=dest+i+j;
					mByte1=src+i+j+channels;
					pByte1=dest+i+j+channels;
					if(colourMode){
						colourmax=pByte1[2]>pByte[2]?pByte1[2]-pByte[2]:pByte[2]-pByte1[2];
						colour=pByte1[1]>pByte[1]?pByte1[1]-pByte[1]:pByte[1]-pByte1[1];
						colourmax=colourmax<colour?colour:colourmax;
					}else{
						colourmax=mByte1[0]>mByte[0]?mByte1[0]-mByte[0]:mByte[0]-mByte1[0];
						colour=mByte1[1]>mByte[1]?mByte1[1]-mByte[1]:mByte[1]-mByte1[1];
						colourmax=colourmax<colour?colour:colourmax;
						colour=mByte1[2]>mByte[2]?mByte1[2]-mByte[2]:mByte[2]-mByte1[2];
						colourmax=colourmax<colour?colour:colourmax;
					}
					if(colourmax<=spread && pByte[0]!=0 && pByte1[0]==0){
						pByte1[0]=255;
						count++;
					}
					mByte=src+i+j;
					pByte=dest+i+j;
					mByte1=src+i+j+step;
					pByte1=dest+i+j+step;
					if(colourMode){
						colourmax=pByte1[2]>pByte[2]?pByte1[2]-pByte[2]:pByte[2]-pByte1[2];
						colour=pByte1[1]>pByte[1]?pByte1[1]-pByte[1]:pByte[1]-pByte1[1];
						colourmax=colourmax<colour?colour:colourmax;
					}else{
						colourmax=mByte1[0]>mByte[0]?mByte1[0]-mByte[0]:mByte[0]-mByte1[0];
						colour=mByte1[1]>mByte[1]?mByte1[1]-mByte[1]:mByte[1]-mByte1[1];
						colourmax=colourmax<colour?colour:colourmax;
						colour=mByte1[2]>mByte[2]?mByte1[2]-mByte[2]:mByte[2]-mByte1[2];
						colourmax=colourmax<colour?colour:colourmax;	
					}
					if(colourmax<=spread && pByte[0]!=0 && pByte1[0]==0){
						pByte1[0]=255;							
						count++;
					}
				}
			}
			for(j=hs-step;j>=step;j-=step) {
				for(i=wc-channels;i>=channels;i-=channels) {
					mByte=src+i+j;
					pByte=dest+i+j;
					mByte1=src+i+j-channels;
					pByte1=dest+i+j-channels;
					if(colourMode){
						colourmax=pByte1[2]>pByte[2]?pByte1[2]-pByte[2]:pByte[2]-pByte1[2];
						colour=pByte1[1]>pByte[1]?pByte1[1]-pByte[1]:pByte[1]-pByte1[1];
						colourmax=colourmax<colour?colour:colourmax;
					}else{
						colourmax=mByte1[0]>mByte[0]?mByte1[0]-mByte[0]:mByte[0]-mByte1[0];
						colour=mByte1[1]>mByte[1]?mByte1[1]-mByte[1]:mByte[1]-mByte1[1];
						colourmax=colourmax<colour?colour:colourmax;
						colour=mByte1[2]>mByte[2]?mByte1[2]-mByte[2]:mByte[2]-mByte1[2];
						colourmax=colourmax<colour?colour:colourmax;	
					}
					if(colourmax<=spread && pByte[0]!=0 && pByte1[0]==0){
						pByte1[0]=255;							
						count++;
					}
					mByte=src+i+j;
					pByte=dest+i+j;
					mByte1=src+i+j-step;
					pByte1=dest+i+j-step;
					if(colourMode){
						colourmax=pByte1[2]>pByte[2]?pByte1[2]-pByte[2]:pByte[2]-pByte1[2];
						colour=pByte1[1]>pByte[1]?pByte1[1]-pByte[1]:pByte[1]-pByte1[1];
						colourmax=colourmax<colour?colour:colourmax;
					}else{
						colourmax=mByte1[0]>mByte[0]?mByte1[0]-mByte[0]:mByte[0]-mByte1[0];
						colour=mByte1[1]>mByte[1]?mByte1[1]-mByte[1]:mByte[1]-mByte1[1];
						colourmax=colourmax<colour?colour:colourmax;
						colour=mByte1[2]>mByte[2]?mByte1[2]-mByte[2]:mByte[2]-mByte1[2];
						colourmax=colourmax<colour?colour:colourmax;
					}
					if(colourmax<=spread && pByte[0]!=0 && pByte1[0]==0){
						pByte1[0]=255;							
						count++;
					}
				}
			}			
		}while(count>0);
	}
	for(j=0;j<hs-step;j+=step) {
		for(i=0;i<wc-channels;i+=channels) {
			mByte=src+i+j;
			pByte=dest+i+j;				
			pByte[1]=pByte[0];				
			pByte[2]=pByte[0];	
		}
	}
	
}

int areaCut(IplImage *memopic,IplImage *temppic,bool ignoreEdge=false){
	//只保留面积最大的区域，返回最大的面积
	int hei    = memopic->height;
	int wid     = memopic->width;
	int step      = memopic->widthStep;
	int channels  = memopic->nChannels;
	int hs=hei*step;
	int wc=wid*channels;
	uchar* src = (uchar *)memopic->imageData;
	uchar* dest = (uchar *)temppic->imageData;
	static int i=0,j=0,k=0,l=0,m=0,n=0,o=0;//循环变量
	uchar* mByte=src;//原图指针
	uchar* pByte=dest;//预览图指针
	uchar* pByte1=dest;//预览图指针
	int areamax=0;
	int count=0;
	int countmax=0;	
	int stackTop=0;
	int id=ignoreEdge?3:2;//待标记的区域ID，从2开始标记
	int countmaxid=id;// 最大区域面积对应的区域ID
	bool isEdge=false;
	if(wid<10 || hei<10){
		return 0;
	}
	if(step%channels!=0){
		return 0;
	}	
	for(j=0;j<hs;j+=step) {
		for(i=0;i<wc;i+=channels) {
			 mByte=src+i+j;
			 pByte=dest+i+j;
			 pByte[0]=0;
			 pByte[1]=0;
			 pByte[2]=mByte[0]>127?1:0;			 
		}
	}
	j=0;
	while(j<hei) {
		i=0;
		while(i<wid) {
			k=i;
			l=j;
			pByte=dest+k*channels+l*step;
			if(pByte[2]==1 && pByte[1]==0 && pByte[0]==0){
				k=i;
				l=j;
				stackTop=0;
				src[stackTop]=(uchar)(l&255);
				src[stackTop+1]=(uchar)((k&15)<<4|l>>8&15);
				src[stackTop+2]=(uchar)(k>>4&255);
				stackTop+=channels;
				count=0;
				pByte=dest+k*channels+l*step;

				pByte[0]=id>>16&0xff;//标为已计算
				pByte[1]=id>>8&0xff;
				pByte[2]=id&0xff;
				isEdge=false;
				while(stackTop>0){
					stackTop-=channels;
					k=(int)(src[stackTop+2])<<4|(int)(src[stackTop+1])>>4;
					l=((int)(src[stackTop+1])&15)<<8|(int)(src[stackTop]);
					if(k<0 || k>=wid ||l<0 || l>=wid){
						break;
					}
					count++;
					pByte=dest+k*channels+l*step;
					if(ignoreEdge && (isEdge || i==0 || i==wid-1 || j==0 || j==hei-1)){
						pByte[0]=0;//标为边界
						pByte[1]=0;
						pByte[2]=2;
						isEdge=true;
					}else{
						pByte[0]=id>>16&0xff;//标为已计算
						pByte[1]=id>>8&0xff;
						pByte[2]=id&0xff;
					}
					
					
					if(k<wid-1 && (pByte1=pByte+channels,pByte1[2]==1) && pByte1[1]==0 && pByte1[0]==0 && stackTop<hs+wc-channels){
						m=k+1;
						n=l;
						src[stackTop]=(uchar)(n&255);
						src[stackTop+1]=(uchar)((m&15)<<4|n>>8&15);
						src[stackTop+2]=(uchar)(m>>4&255);
						stackTop+=channels;	
					}
					if(l<hei-1 && (pByte1=pByte+step,pByte1[2]==1) && pByte1[1]==0 && pByte1[0]==0 && stackTop<hs+wc-channels){
						m=k;
						n=l+1;						
						src[stackTop]=(uchar)(n&255);
						src[stackTop+1]=(uchar)((m&15)<<4|n>>8&15);
						src[stackTop+2]=(uchar)(m>>4&255);
						stackTop+=channels;	
					}					
					if(k>0 && (pByte1=pByte-channels,pByte1[2]==1) && pByte1[1]==0 && pByte1[0]==0 && stackTop<hs+wc-channels){
						m=k-1;
						n=l;
						src[stackTop]=(uchar)(n&255);
						src[stackTop+1]=(uchar)((m&15)<<4|n>>8&15);
						src[stackTop+2]=(uchar)(m>>4&255);
						stackTop+=channels;
					}					
					if(l>0 && (pByte1=pByte-step,pByte1[2]==1) && pByte1[1]==0 && pByte1[0]==0 && stackTop<hs+wc-channels){
						m=k;
						n=l-1;
						src[stackTop]=(uchar)(n&255);
						src[stackTop+1]=(uchar)((m&15)<<4|n>>8&15);
						src[stackTop+2]=(uchar)(m>>4&255);
						stackTop+=channels;
					}
					
					/*if(k<wid-1 && l<hei-1 && (pByte1=pByte+channels+step,pByte1[2]==1) && pByte1[1]==0 && pByte1[0]==0 && stackTop<hs+wc-channels){
						m=k+1;
						n=l+1;
						src[stackTop]=(uchar)(n&255);
						src[stackTop+1]=(uchar)((m&15)<<4|n>>8&15);
						src[stackTop+2]=(uchar)(m>>4&255);
						stackTop+=channels;	
					}					
					if(k<wid-1 && l>0 && (pByte1=pByte+channels-step,pByte1[2]==1) && pByte1[1]==0 && pByte1[0]==0 && stackTop<hs+wc-channels){
						m=k+1;
						n=l-1;						
						src[stackTop]=(uchar)(n&255);
						src[stackTop+1]=(uchar)((m&15)<<4|n>>8&15);
						src[stackTop+2]=(uchar)(m>>4&255);
						stackTop+=channels;	
					}					
					if(k>0 && l<hei-1 && (pByte1=pByte-channels+step,pByte1[2]==1) && pByte1[1]==0 && pByte1[0]==0 && stackTop<hs+wc-channels){
						m=k-1;
						n=l+1;
						src[stackTop]=(uchar)(n&255);
						src[stackTop+1]=(uchar)((m&15)<<4|n>>8&15);
						src[stackTop+2]=(uchar)(m>>4&255);
						stackTop+=channels;
					}					
					if(k>0 && l>0 && (pByte1=pByte-channels-step,pByte1[2]==1) && pByte1[1]==0 && pByte1[0]==0 && stackTop<hs+wc-channels){
						m=k-1;
						n=l-1;
						src[stackTop]=(uchar)(n&255);
						src[stackTop+1]=(uchar)((m&15)<<4|n>>8&15);
						src[stackTop+2]=(uchar)(m>>4&255);
						stackTop+=channels;
					}*/
				}
				if(countmax<count){
					countmax=count;
					countmaxid=id;
				}
			 }
			 id++;
			 if(ignoreEdge){
				 if(i==0){
					 i=wid-1;
				 }else if(i==wid-1){
					 i=1;
				 }else if(i==wid-2){
					 i=wid;
				 }else{
					 i++;
				 }
			 }else{
				i++;
			 }
		}
		if(ignoreEdge){
			if(j==0){
				j=hei-1;
			}else if(j==hei-1){
				j=1;
			}else if(j==hei-2){
				j=hei;
			}else{
				j++;
			}
		}else{
			j++;
		}
	}	
	for(j=0;j<hs;j+=step) {
		for(i=0;i<wc;i+=channels) {
			 
			 mByte=src+i+j;
			 pByte=dest+i+j;
			
			 id=(int)(pByte[0])<<16|(int)(pByte[1])<<8|(int)(pByte[2]);
			 if(id==countmaxid || ignoreEdge && id==2){
				mByte[0]=255;
				mByte[1]=255;
				mByte[2]=255;
			 }else{
				mByte[0]=0;
				mByte[1]=0;
				mByte[2]=0;
			 }

		}
	}
	return countmax;
}

int* getJoints(IplImage* memopic){
	//获得重心和手指端点（手指端点坐标的获取未实现）
	int hei    = memopic->height;
	int wid     = memopic->width;
	int step      = memopic->widthStep;
	int channels  = memopic->nChannels;
	int hs=hei*step;
	int wc=wid*channels;
	uchar* src = (uchar *)memopic->imageData;	
	int i=0,j=0,k=0,l=0,m=0,n=0,o=0;//循环变量
	uchar* mByte=src;//原图指针
	static int arr[16];
	arr[0]=0;//重心坐标
	arr[1]=0;//重心坐标
	
	int sum=0;	
	int handBottom=hei-1;
	int handTop=-1;
	int handTopi=0;
	static int left=-1;
	static int right=-1;
	static int widmax=0;	
	for(j=0;j<=hei;j++) {
		left=-1;
		right=-1;
		for(i=0;i<wid;i++) {
			mByte=src+i*channels+j*step;			
			if(mByte[0]>127 && left<0){				
				left=i;
			}
			if(mByte[0]>127){
				right=i;
			}
		}
		if(widmax<right-left){
			widmax=right-left;
		}
	}
	for(j=0;j<=hei;j++) {
		for(i=0;i<wid;i++) {
			mByte=src+i*channels+j*step;
			if(mByte[0]>127 && j<=handBottom){
				if(handTop<0){
					handTopi=i;
					handTop=j;
					handBottom=(int)(j+widmax*1.618);
					if(handBottom>hei-1){
						handBottom=hei-1;
					}
				}				
				arr[0]+=i;
				arr[1]+=j;
				sum++;				
			}
			if(mByte[0]!=mByte[channels] || mByte[0]!=mByte[step]){
				
			}
		}
	}
	if(sum!=0){
		arr[0]/=sum;
		arr[1]/=sum;
	}else{
		arr[0]=wid/2;
		arr[1]=hei/2;
	}
	if(handTop==-1){
		handTopi=wid/2;
		handTop=hei/2;
	}
	arr[2]=sum;
	arr[3]=handBottom;
	arr[4]=handTopi;
	arr[5]=handTop;
	return arr;
}

void getMouseDxy(double hdx,double hdy,int &mdx,int &mdy){//从手的有效偏移量按一定关系获取鼠标偏移量
	static double v=0;
	static double hdxprev=0,hdyprev=0;
	double a=sqrt(hdx*hdx+hdy*hdy)*5;
	if(hdx==0 && hdy==0){
		v=0;
	}else{
		if(v+a<30){
			v+=a;
		}else{
			v=50;
		}		
	}	
	mdx=(int)(hdx*v);
	mdy=(int)(hdy*v);
}

void CGestureTestDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	CWnd *cwdg=FindWindowEx(NULL,NULL,NULL,"GestureTest");
	CWnd *cwdt=GetForegroundWindow();
	if(this!=cwdt && cwdg==cwdt){		
		CDialogEx::OnTimer(nIDEvent);
		return;
	}
	//if(GetDlgItemText(IDC_EDIT2,str),str=="-"){
		//DrawToHdc(m_Frame);
		//CDialogEx::OnTimer(nIDEvent);
		//return;
	//}
	if(!UpdateData(TRUE)){
		UpdateData(FALSE);
		CDialogEx::OnTimer(nIDEvent);
		return;
	}
	if(m_Video==NULL){	
		CDialogEx::OnTimer(nIDEvent);
		return;
	}
	if(m_c0==TRUE){
		if(m_e02<=0 || m_e03<=0){
			Invalidate();
			CDialogEx::OnTimer(nIDEvent);
			return;
		}
		m_Captured=cvQueryFrame(m_Video);
		if(m_Frame!=NULL && (m_Frame->width!=m_e02 || m_Frame->height!=m_e03)){
			if(m_FrameCreated){
				cvReleaseImage(&m_Frame);
			}
			m_Frame=NULL;
		}
		if(m_Frame==NULL){			
			m_Frame=cvCreateImage(cvSize(m_e02,m_e03), m_Captured->depth, m_Captured->nChannels);
			m_FrameCreated=true;
		}
		cvResize(m_Captured,m_Frame,(m_Captured->width)>(m_Frame->width)?CV_INTER_LINEAR:CV_INTER_AREA);
		//DrawToHdc(m_Frame);
		//CDialogEx::OnTimer(nIDEvent);
		//return;
	}else{
		m_FrameCreated=false;
		m_Frame=cvQueryFrame(m_Video);
	}
	if(m_Frame==NULL){
		CDialogEx::OnTimer(nIDEvent);
		return;
	}
	int hei    = m_Frame->height;
	int wid     = m_Frame->width;
	int step      = m_Frame->widthStep;
	int channels  = m_Frame->nChannels;
	int hs=hei*step;
	int wc=wid*channels;
	if(channels<3){
		CDialogEx::OnTimer(nIDEvent);
		return;
	}
	if(m_GrabFrame!=NULL && (m_GrabFrame->width!=wid || m_GrabFrame->height!=hei)){
		cvReleaseImage(&m_GrabFrame);
		m_GrabFrame=NULL;
		Invalidate();
	}	
	if(m_GrabFrame==NULL){
		m_e02=wid;
		m_e03=hei;
		UpdateData(FALSE);
		m_GrabFrame=cvCreateImage(cvGetSize(m_Frame), m_Frame->depth, m_Frame->nChannels);		
	}
	if(m_temp!=NULL && (m_temp->width!=wid || m_temp->height!=hei)){
		cvReleaseImage(&m_temp);
		m_temp=NULL;	
	}	
	if(m_temp==NULL){		
		m_temp=cvCreateImage(cvGetSize(m_Frame), m_Frame->depth, m_Frame->nChannels);		
	}

	CString str="";
	

	
	bool willUpdateDataFalse=false;
	if(m_e11<0){
		m_e11=0;
		willUpdateDataFalse=true;
	}
	if(m_e11>7){
		m_e11=7;
		willUpdateDataFalse=true;
	}
	if(m_e12<0){
		m_e12=0;
		willUpdateDataFalse=true;
	}
	if(m_e12>255){
		m_e12=255;
		willUpdateDataFalse=true;
	}
	if(m_e13<0){
		m_e13=0;
		willUpdateDataFalse=true;
	}
	if(m_e13>255){
		m_e13=255;
		willUpdateDataFalse=true;
	}
	if(willUpdateDataFalse){
		UpdateData(FALSE);
	}
	
	uchar* src = (uchar *)m_Frame->imageData;
	uchar* dest = (uchar *)m_GrabFrame->imageData;
	uchar* mByte = src;
	uchar* pByte = dest;
	int colour=0;
	int i=0,j=0,k=0;
	bool preshow=false;//显示m_GrabFrame

	//step1
	int colourmax=0;//最大色差
	if(smoothMode==1){
		cvSmooth(m_Frame, m_GrabFrame, CV_MEDIAN, 2*m_e11+1, 0, 0, 0);		
	}else if(smoothMode==2){
		cvSmooth(m_Frame, m_GrabFrame, CV_GAUSSIAN, 2*m_e11+1, 2*m_e11+1, 0, 0);		
	}	
	if(smoothMode!=0){		
		blurFixFilter(m_Frame, m_GrabFrame,m_e12,m_e13);
	}
	if(m_c1==TRUE){
		ruihuaFilter(m_Frame, m_GrabFrame,m_erhsl,m_erhbj,0);
		cvCopy(m_GrabFrame,m_Frame);
	}
	//str.Format("%d",m_e12);
	//SetWindowText(str);

	//step2
	if(m_r1>=1){
		preshow=true;
		colourSelect(m_Frame,m_GrabFrame,m_e21,m_e22,m_e23,m_c2==TRUE,false);
	}

	uchar *tempori=(uchar *)m_temp->imageData;
	uchar *tByte=tempori;	
	if(m_r1>=2)
	{
		preshow=true;
		areaCut(m_GrabFrame,m_temp);
		cvNot(m_GrabFrame,m_temp);
		areaCut(m_temp,m_GrabFrame,true);
		cvNot(m_temp,m_GrabFrame);
	}
	if(m_r1>=3)
	{
		preshow=true;
		cvCopy(m_GrabFrame,m_temp);
		int *joints=getJoints(m_GrabFrame);
		if(m_ctop==FALSE){
			centx=joints[0];
			centy=joints[1];
		}else{
			centx=joints[4];
			centy=joints[5];
		}
		zone=joints[2];
		if(centx>=0 && centx<wid && centy>=0 && centx<hei){
			dest[centx*channels+centy*step+1]=0;
			dest[centx*channels+centy*step+2]=255;
			if(centx>0){
				dest[centx*channels-channels+centy*step+1]=0;
				dest[centx*channels-channels+centy*step+2]=255;
			}
			if(centx<wid-1){
				dest[centx*channels+channels+centy*step+1]=0;
				dest[centx*channels+channels+centy*step+2]=255;
			}
			if(centy>0){
				dest[centx*channels+centy*step-step+1]=0;
				dest[centx*channels+centy*step-step+2]=255;
			}
			if(centy<hei-1){
				dest[centx*channels+centy*step+step+1]=0;
				dest[centx*channels+centy*step+step+2]=255;
			}
		}
	}
	
	if(preshow){
		DrawToHdc(m_GrabFrame);
	}else{
		DrawToHdc(m_Frame);
	}

	sizeprev=(double)zone/(wid*hei);
	size=(double)zone/(wid*hei);
	if(screenPaintMode && (posleng&1)==0){
		str.Format("%f",size);
		SetWindowText(str);
		if(pen==NULL){
			static CPen pent;
			pent.CreatePen(PS_SOLID,2,RGB(255,0,0));
			pen=&pent;
		}
		pWinDC->SelectObject(pen);
		/*if(posleng<2048){
			pos[posleng]=1920/wid*centx;
			pos[posleng+1]=1080/hei*centy;
			posleng+=2;
		}
		for(i=2;i<posleng;i++){
			pWinDC->MoveTo(pos[i-2],pos[i-1]);
			pWinDC->LineTo(pos[i],pos[i+1]);
		}*/
		
		if(posleng>0){
			pos[0]=pos[2];
			pos[1]=pos[3];
		}
		pos[2]=centx/(double)wid;
		pos[3]=centy/(double)hei;
		/*if(posleng>0 && (abs(pos[2]-pos[0])>0.3 || abs(pos[3]-pos[1])>0.3)){
			pos[2]=pos[0];
			pos[3]=pos[1];
		}*/
		if(posleng>0 && size>=0.08){
			pWinDC->MoveTo((int)(screenwid-screenwid*pos[0]),(int)(screenhei*pos[1]));
			pWinDC->LineTo((int)(screenwid-screenwid*pos[2]),(int)(screenhei*pos[3]));
		}else{
			posleng=2;
		}
		//if(size<0.08){
			//posleng=0;
		//}
	}
	
	static CPoint mousePoint;
	if(mouseClickMode){
		
		if(!moveAbolished){
			xrateprev=xrate;
			yrateprev=yrate;
		}else{
			xrateprev=0.5;
			yrateprev=0.5;
		}
		xrate=1.0-(double)centx/wid;
		yrate=(double)centy/hei;
		if(fabs(xrateprev-xrate)>0.15 || fabs(yrateprev-yrate)>0.15 || sizeprev<=0.0 || size/sizeprev>1.5){
			moveAbolished=true;
		}else{
			moveAbolished=false;
		}
		moveAbolished=false;
		if(size>0.05 && size<0.4 && !moveAbolished){
			GetCursorPos(&mousePoint);
			double movermin=0.01;//手在x和y位于[0.5- movermin, 0.5+ movermin]的矩形内鼠标不动，有效偏移量=手离重心的距离- movermin。
			double movementx=0; //有效偏移量的横坐标
			double movementy=0; //有效偏移量的纵坐标
			int mpdx=0,mpdy=0;//获取鼠标偏移量
			if(xrate>0.5+movermin){
				movementx =xrate-0.5-movermin;//获取手的有效偏移量
			}else if(xrate<0.5-movermin){
				movementx =xrate-0.5+movermin;
			}
			if(yrate>0.5+movermin){
				movementy =yrate-0.5-movermin;
			}else if(yrate<0.5-movermin){
				movementy =yrate-0.5+movermin;
			}
			getMouseDxy(movementx,movementy,mpdx,mpdy);//从手的有效偏移量按一定关系获取鼠标偏移量

			mousePoint.x+=mpdx;
			mousePoint.y+=mpdy;
			if(mousePoint.x<0){
				mousePoint.x=0;
			}
			if(mousePoint.x>=screenwid){
				mousePoint.x=screenwid-1;
			}
			if(mousePoint.y<0){
				mousePoint.y=0;
			}
			if(mousePoint.y>=screenhei){
				mousePoint.y=screenhei-1;
			}
			str.Format("%.2f,%.2f,%.2f,%d,%d",size,movementx,movementy,mpdx,mpdy);			
			SetWindowText(str);
			SetCursorPos(mousePoint.x,mousePoint.y);
			if(size>m_ea1){
				if(!camMouseIsDown){
					mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
				}
				camMouseIsDown=true;
			}else{
				//if(camMouseIsDown){
					mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
				//}
				camMouseIsDown=false;
			}
		}else if(camMouseIsDown){
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			camMouseIsDown=false;
		}
	}else if(camMouseIsDown){
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		camMouseIsDown=false;
	}


	
	CDialogEx::OnTimer(nIDEvent);
}



void CGestureTestDlg::DrawToHdc(IplImage *image)
{
	if(image==NULL || image->nChannels<3){
		return;
	}
	int hei    = image->height;
	int wid     = image->width;		
	uchar* data      = (uchar *)image->imageData;
	static uchar buffer[sizeof(BITMAPINFOHEADER) + 1024];  
    BITMAPINFO* bmi = (BITMAPINFO*)buffer;

	BITMAPINFOHEADER* bmih = &(bmi->bmiHeader);
	memset( bmih, 0, sizeof(*bmih));  
	bmih->biSize = sizeof(BITMAPINFOHEADER);  
	bmih->biWidth = wid;  
	bmih->biHeight = image->origin ? abs(hei) : -abs(hei);  
	bmih->biPlanes = 1;  
	bmih->biBitCount = (unsigned short)((image->depth & 255)*image->nChannels);  
	bmih->biCompression = BI_RGB;
	
	SetDIBitsToDevice(hDC, 0, 0, wid, hei, 0, 0, 0, hei, data ,bmi, DIB_RGB_COLORS);
}


void CGestureTestDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	smoothMode=1;
}


void CGestureTestDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	smoothMode=2;
}


void CGestureTestDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	smoothMode=0;
}


void CGestureTestDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	CColorDialog dlg(m_e21,CC_FULLOPEN);
	dlg.DoModal();
	m_e21=dlg.GetColor();
	UpdateData(FALSE);
}


void CGestureTestDlg::OnClickedStatic1()
{
	// TODO: 在此添加控件通知处理程序代码
	CPoint point;
	GetCursorPos(&point);
	GetDlgItem(IDC_STATIC1)->ScreenToClient(&point);
	CString str;
	str.Format("%d,%d",point.x,point.y);
	SetWindowText(str);
	if((point.x)<0 || (point.x)>=(m_Frame->width) || (point.y)<0 || (point.y)>=(m_Frame->height)){
		return;
	}
	uchar* src = (uchar *)m_Frame->imageData;
	uchar* mByte=src+point.x*(m_Frame->nChannels)+point.y*(m_Frame->widthStep);
	m_e21=(int)mByte[0]<<16|(int)mByte[1]<<8|(int)mByte[2];
	UpdateData(FALSE);
}


HBRUSH CGestureTestDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO:  在此更改 DC 的任何特性
	if(pWnd->GetDlgCtrlID()   ==   IDC_EDIT4)  
    {  
		HBRUSH   m_hbrDlg;
		COLORREF colour=(COLORREF)m_e21;
		m_hbrDlg=CreateSolidBrush(colour); 
		pDC-> SetBkMode(TRANSPARENT);		
		if(GetRValue(colour)*3+GetGValue(colour)*6+GetBValue(colour)*1>1270){
			pDC-> SetTextColor(RGB(0,0,0)); 
		}else{
			pDC-> SetTextColor(RGB(255,255,255)); 
		}
		return   m_hbrDlg;
		//pDC->SetTextColor(m_e21);
    }
    return   hbr;
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	
}


void CGestureTestDlg::OnBnClickedRadio3()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CGestureTestDlg::OnEnChangeEdit13()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CGestureTestDlg::OnEnChangeEdit12()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CGestureTestDlg::OnEnChangeEdit11()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_Video!=NULL)
	{
		cvReleaseCapture(&m_Video);
	}
	m_Video=cvCreateCameraCapture(m_e01);
	if (m_Video==NULL)
	{		
		m_e01=0;
		UpdateData(FALSE);
		m_Video=cvCreateCameraCapture(m_e01);		
	}
	if (m_Video==NULL)
	{
		MessageBox("无法打开摄像头");		
	}	
}


void CGestureTestDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	screenPaintMode=!screenPaintMode;
	if(!screenPaintMode){
		return;
	}
	mouseClickMode=false;
	m_r1=3;
	UpdateData(FALSE);
	if(pWinDC==NULL){		
		static CWnd*  pWndw= CWnd::GetDesktopWindow();	
		static CWindowDC winDC(pWndw);
		pWinDC=&winDC;
	}
	posleng=0;
}


void CGestureTestDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	if(m_r1!=3){
		m_r1=3;
		UpdateData(FALSE);
	}
	mouseClickMode=!mouseClickMode;
	if(!mouseClickMode){
		return;
	}
	screenPaintMode=false;
	xrateprev=0.5;
	yrateprev=0.5;
	xrate=0.5;
	yrate=0.5;
	moveAbolished=false;
	camMouseIsDown=false;
}

void CGestureTestDlg::MoveControls(int pictureBoxWidth,int pictureBoxHeight,bool sizeWindow){
	CWnd* pWnd = GetWindow(GW_CHILD);//其他控件
	CWnd* pWnd0 = GetDlgItem(IDC_STATIC1);//图片控件

	CRect rect,rect0,rectr;
	pWnd0->GetWindowRect(&rect0);
	ScreenToClient(&rect0);
	int wid0=rect0.Width();	
	int dx=pictureBoxWidth-wid0;
	rect0.right+=dx;
	int centy=(int)(494*0.382+12);
	if(pictureBoxHeight>0){
		/*if(pictureBoxHeight<480){
			rect0.top=(int)(12+centy-pictureBoxHeight*0.382);
			rect0.bottom=(int)ceil(12+centy+pictureBoxHeight*0.618);
		}else{*/
			rect0.top=12;
			rect0.bottom=12+pictureBoxHeight;
		//}
	}
	pWnd0->MoveWindow(&rect0);//获取图片控件信息并移动它
	
	
    while(pWnd!=NULL)
    {		
		if(pWnd!=pWnd0){
			pWnd->GetWindowRect(&rect);
			ScreenToClient(&rect);
			rect.left+=dx;
			rect.right+=dx;
			pWnd->MoveWindow(&rect);
		}
		pWnd = pWnd->GetWindow(GW_HWNDNEXT);		
    }
	if(sizeWindow){
		GetWindowRect(&rectr);
		rectr.right+=dx;
		if(pictureBoxHeight>500){
			rectr.bottom=rectr.top+pictureBoxHeight+80;
		}
		MoveWindow(&rectr);
	}
}

void CGestureTestDlg::OnSetfocusPictureWid()
{
	// TODO: 在此添加控件通知处理程序代码	
	pwid0=m_Frame->width;
}


void CGestureTestDlg::OnKillfocusPictureWid()
{
	// TODO: 在此添加控件通知处理程序代码
	int pwidt=m_Frame->width;
	if(pwid0!=pwidt){
		MoveControls(pwidt>screenwid-300?screenwid-300:pwidt);
	}
}


void CGestureTestDlg::OnSetfocusPictureHei()
{
	// TODO: 在此添加控件通知处理程序代码
	phei0=m_Frame->height;
}


void CGestureTestDlg::OnKillfocusPictureHei()
{
	// TODO: 在此添加控件通知处理程序代码
	int pheit=m_Frame->height;
	if(phei0!=pheit){
		MoveControls(m_Frame->width,pheit>screenhei-100?screenhei-100:pheit);
	}
}
