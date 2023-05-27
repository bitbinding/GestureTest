
// GestureTestDlg.h : ͷ�ļ�
//

#pragma once
#include <cv.h>
#include <highgui.h>
#include <vector>
#include "afxwin.h"

// CGestureTestDlg �Ի���
class CGestureTestDlg : public CDialogEx
{
// ����
public:
	CGestureTestDlg(CWnd* pParent = NULL);	// ��׼���캯��
	void DrawToHdc(IplImage *image);//��ͼƬ����hdc��
	void MoveControls(int pictureBoxWidth,int pictureBoxHeight=0,bool sizeWindow=true);//ˮƽ�ƶ��ؼ�
	CvCapture * m_Video;//��Ƶָ��
	IplImage* m_Captured;//��Ƶ�е�ͼƬ
	IplImage* m_Frame;//�ݴ�ͼƬ
	IplImage* m_GrabFrame;//Ԥ��ͼƬ
	IplImage* m_temp;//��ʱͼƬ
	bool m_FrameCreated;//�ݴ�ͼƬ�Ƿ�Ϊ�ֶ�������
	int smoothMode;//ƽ��ģʽ
	int centx;//���ĺ�����
	int centy;//����������
	int zone;//�������
	int pwid0;//���������ñ༭��ǰͼƬ�Ŀ��ֵ
	int phei0;//����߶����ñ༭��ǰͼƬ�ĸ߶�ֵ
	
	//IDC_STATIC1�ĸ�������
	CDC *pDC;
	HDC hDC;
	CWnd *pwnd;
	CRect rect;

	//��Ļ��ͼ
	bool screenPaintMode;
	CWindowDC *pWinDC;
	CPen *pen;
	double pos[4];
	int posleng;
	int screenwid;
	int screenhei;

	//�����
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
// �Ի�������
	enum { IDD = IDD_GESTURETEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
