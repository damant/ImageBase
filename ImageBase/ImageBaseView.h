// 这段 MFC 示例源代码演示如何使用 MFC Microsoft Office Fluent 用户界面 
// (“Fluent UI”)。该示例仅供参考，
// 用以补充《Microsoft 基础类参考》和 
// MFC C++ 库软件随附的相关电子文档。
// 复制、使用或分发 Fluent UI 的许可条款是单独提供的。
// 若要了解有关 Fluent UI 许可计划的详细信息，请访问  
// http://go.microsoft.com/fwlink/?LinkId=238214。
//
// 版权所有(C) Microsoft Corporation
// 保留所有权利。

// ImageBaseView.h : CImageBaseView 类的接口
//

#pragma once


class CImageBaseView : public CView
{
protected: // 仅从序列化创建
	CImageBaseView();
	DECLARE_DYNCREATE(CImageBaseView)

// 特性
public:
	CImageBaseDoc* GetDocument() const;
	vector<GWindow*> mVecGwnd;
private:
	bool mSyncFlag;//同步浏览标志
// 操作
public:
	void OpenImgFile(CString);//用gimage打开图片，gwindow显示
protected:
	void _Layout();
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CImageBaseView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnRBtnSuperres();
	afx_msg void OnRBtnOpenAnother();
	afx_msg void OnUpdateRCheckSync(CCmdUI *pCmdUI);
	afx_msg void OnRCheckSync();
	afx_msg void OnTestShowProcess();
	afx_msg void OnTestHideProcess();
};

#ifndef _DEBUG  // ImageBaseView.cpp 中的调试版本
inline CImageBaseDoc* CImageBaseView::GetDocument() const
   { return reinterpret_cast<CImageBaseDoc*>(m_pDocument); }
#endif

