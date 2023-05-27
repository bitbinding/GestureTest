
// GestureTestDlg.h : 头文件
//

#pragma once
#include <cv.h>
#include <highgui.h>
#include <vector>
#include "afxwin.h"

// CGestureTestDlg 对话框
class CGestureTestDlg : public CDialogEx
{
// 构造
public:
	CGestureTestDlg(CWnd* pParent = NULL);	// 标准构造函数
	void DrawToHdc(IplImage *image);//将图片画到hdc中
	void MoveControls(int pictureBoxWidth,int pictureBoxHeight=0,bool sizeWindow=true);//水平移动控件
	CvCapture * m_Video;//视频指针
	IplImage* m_Captured;//视频中的图片
	IplImage* m_Frame;//暂存图片
	IplImage* m_GrabFrame;//预览图片
	IplImage* m_temp;//临时图片
	bool m_FrameCreated;//暂存图片是否为手动创建的
	int smoothMode;//平滑模式
	int centx;//重心横坐标
	int centy;//重心纵坐标
	int zone;//区域面积
	int pwid0;//进入宽度设置编辑框前图片的宽度值
	int phei0;//进入高度设置编辑框前图片的高度值
	
	//IDC_STATIC1的各个属性
	CDC *pDC;
	HDC hDC;
	CWnd *pwnd;
	CRect rect;

	//屏幕绘图
	bool screenPaintMode;
	CWindowDC *pWinDC;
	CPen *pen;
	double pos[4];
	int posleng;
	int screenwid;
	int screenhei;

	//鼠标点击
	bool mouseClickMode;
	double size;
	double sizeprev;
	double xrateprev;
	double yrateprev;
	double xrate;
	double yrate;
	bool moveAbolished;
	bool camMouseIsDown;
	int wid0;
// 对话框数据
	enum { IDD = IDD_GESTURETEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnBnClickedOk();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
//	int m_e11;
//	int m_e12;
	int m_e11;
	int m_e12;
//	int m_r1;
//	int m_r1;
	afx_msg void OnBnClickedButton3();
//	int m_e21;
//	CEdit m_e13;
	int m_e13;
	int m_e21;
	int m_e22;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnClickedStatic1();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	int m_e23;
//	CEdit m_erhsl;
//	int m_erhsl;
	int m_erhbj;
	BOOL m_c1;
	float m_erhsl;
	BOOL m_c2;
//	int m_e31;
//	int m_e32;
	afx_msg void OnBnClickedRadio3();
//	CButton m_r1;
	int m_r1;
//	CString m_e01;
//	CString m_e02;
	afx_msg void OnEnChangeEdit13();
//	CEdit m_e03;
	afx_msg void OnEnChangeEdit12();
	afx_msg void OnEnChangeEdit11();
	int m_e01;
	int m_e02;
	int m_e03;
	BOOL m_c0;
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();

	afx_msg void OnSetfocusPictureWid();
	afx_msg void OnKillfocusPictureWid();
	
	afx_msg void OnSetfocusPictureHei();
	afx_msg void OnKillfocusPictureHei();
	double m_ea1;
	BOOL m_ctop;
};
