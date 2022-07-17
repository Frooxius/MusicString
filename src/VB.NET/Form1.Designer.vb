<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.textCode = New System.Windows.Forms.TextBox()
        Me.buttPlay = New System.Windows.Forms.Button()
        Me.buttPause = New System.Windows.Forms.Button()
        Me.buttStop = New System.Windows.Forms.Button()
        Me.spinPlayRate = New System.Windows.Forms.NumericUpDown()
        Me.labelPlayRate = New System.Windows.Forms.Label()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.groupPlayback = New System.Windows.Forms.GroupBox()
        Me.groupGenerate = New System.Windows.Forms.GroupBox()
        Me.spinMaxTime = New System.Windows.Forms.NumericUpDown()
        Me.labelSeconds = New System.Windows.Forms.Label()
        Me.labelStatus = New System.Windows.Forms.Label()
        Me.buttGen = New System.Windows.Forms.Button()
        Me.spinGenRate = New System.Windows.Forms.NumericUpDown()
        Me.labelDoesAnybodyEvenReadThis = New System.Windows.Forms.Label()
        Me.saveWAV = New System.Windows.Forms.SaveFileDialog()
        Me.PictureBox1 = New System.Windows.Forms.PictureBox()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.LinkLabel1 = New System.Windows.Forms.LinkLabel()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.LinkLabel2 = New System.Windows.Forms.LinkLabel()
        CType(Me.spinPlayRate, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.groupPlayback.SuspendLayout()
        Me.groupGenerate.SuspendLayout()
        CType(Me.spinMaxTime, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.spinGenRate, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.PictureBox1, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'textCode
        '
        Me.textCode.Font = New System.Drawing.Font("Lucida Console", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(238, Byte))
        Me.textCode.Location = New System.Drawing.Point(12, 12)
        Me.textCode.Multiline = True
        Me.textCode.Name = "textCode"
        Me.textCode.ScrollBars = System.Windows.Forms.ScrollBars.Vertical
        Me.textCode.Size = New System.Drawing.Size(395, 137)
        Me.textCode.TabIndex = 0
        Me.textCode.Text = "(3[0:d.b.a.:0], [6. 4> pttL.5rrT3p.t.p.U.r.ttt.t 4Rq.3ppO5S:0], |[6.4TT.Z:0])"
        '
        'buttPlay
        '
        Me.buttPlay.Location = New System.Drawing.Point(6, 19)
        Me.buttPlay.Name = "buttPlay"
        Me.buttPlay.Size = New System.Drawing.Size(51, 23)
        Me.buttPlay.TabIndex = 1
        Me.buttPlay.Text = "Play"
        Me.buttPlay.UseVisualStyleBackColor = True
        '
        'buttPause
        '
        Me.buttPause.Location = New System.Drawing.Point(63, 19)
        Me.buttPause.Name = "buttPause"
        Me.buttPause.Size = New System.Drawing.Size(51, 23)
        Me.buttPause.TabIndex = 2
        Me.buttPause.Text = "Pause"
        Me.buttPause.UseVisualStyleBackColor = True
        '
        'buttStop
        '
        Me.buttStop.Location = New System.Drawing.Point(120, 19)
        Me.buttStop.Name = "buttStop"
        Me.buttStop.Size = New System.Drawing.Size(51, 23)
        Me.buttStop.TabIndex = 3
        Me.buttStop.Text = "Stop"
        Me.buttStop.UseVisualStyleBackColor = True
        '
        'spinPlayRate
        '
        Me.spinPlayRate.Location = New System.Drawing.Point(302, 22)
        Me.spinPlayRate.Maximum = New Decimal(New Integer() {192000, 0, 0, 0})
        Me.spinPlayRate.Minimum = New Decimal(New Integer() {1, 0, 0, 0})
        Me.spinPlayRate.Name = "spinPlayRate"
        Me.spinPlayRate.Size = New System.Drawing.Size(81, 20)
        Me.spinPlayRate.TabIndex = 4
        Me.spinPlayRate.Value = New Decimal(New Integer() {44100, 0, 0, 0})
        '
        'labelPlayRate
        '
        Me.labelPlayRate.AutoSize = True
        Me.labelPlayRate.Location = New System.Drawing.Point(228, 24)
        Me.labelPlayRate.Name = "labelPlayRate"
        Me.labelPlayRate.Size = New System.Drawing.Size(68, 13)
        Me.labelPlayRate.TabIndex = 5
        Me.labelPlayRate.Text = "SampleRate:"
        '
        'Label1
        '
        Me.Label1.Location = New System.Drawing.Point(11, 214)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(394, 33)
        Me.Label1.TabIndex = 6
        Me.Label1.Text = "Note: Unusuall SampleRate values might not work properly or at all... Try stick t" & _
            "o 8000, 11025, 22050, 44100, 48000, 96000 and 192000"
        '
        'groupPlayback
        '
        Me.groupPlayback.Controls.Add(Me.buttPlay)
        Me.groupPlayback.Controls.Add(Me.buttPause)
        Me.groupPlayback.Controls.Add(Me.spinPlayRate)
        Me.groupPlayback.Controls.Add(Me.labelPlayRate)
        Me.groupPlayback.Controls.Add(Me.buttStop)
        Me.groupPlayback.Location = New System.Drawing.Point(12, 155)
        Me.groupPlayback.Name = "groupPlayback"
        Me.groupPlayback.Size = New System.Drawing.Size(393, 49)
        Me.groupPlayback.TabIndex = 7
        Me.groupPlayback.TabStop = False
        Me.groupPlayback.Text = "Playback"
        '
        'groupGenerate
        '
        Me.groupGenerate.Controls.Add(Me.spinMaxTime)
        Me.groupGenerate.Controls.Add(Me.labelSeconds)
        Me.groupGenerate.Controls.Add(Me.labelStatus)
        Me.groupGenerate.Controls.Add(Me.buttGen)
        Me.groupGenerate.Controls.Add(Me.spinGenRate)
        Me.groupGenerate.Controls.Add(Me.labelDoesAnybodyEvenReadThis)
        Me.groupGenerate.Location = New System.Drawing.Point(12, 250)
        Me.groupGenerate.Name = "groupGenerate"
        Me.groupGenerate.Size = New System.Drawing.Size(393, 69)
        Me.groupGenerate.TabIndex = 8
        Me.groupGenerate.TabStop = False
        Me.groupGenerate.Text = "Generate WAV"
        '
        'spinMaxTime
        '
        Me.spinMaxTime.Location = New System.Drawing.Point(164, 22)
        Me.spinMaxTime.Maximum = New Decimal(New Integer() {3600, 0, 0, 0})
        Me.spinMaxTime.Minimum = New Decimal(New Integer() {1, 0, 0, 0})
        Me.spinMaxTime.Name = "spinMaxTime"
        Me.spinMaxTime.Size = New System.Drawing.Size(58, 20)
        Me.spinMaxTime.TabIndex = 8
        Me.spinMaxTime.Value = New Decimal(New Integer() {600, 0, 0, 0})
        '
        'labelSeconds
        '
        Me.labelSeconds.AutoSize = True
        Me.labelSeconds.Location = New System.Drawing.Point(96, 24)
        Me.labelSeconds.Name = "labelSeconds"
        Me.labelSeconds.Size = New System.Drawing.Size(62, 13)
        Me.labelSeconds.TabIndex = 9
        Me.labelSeconds.Text = "Max length:"
        '
        'labelStatus
        '
        Me.labelStatus.AutoSize = True
        Me.labelStatus.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(238, Byte))
        Me.labelStatus.Location = New System.Drawing.Point(6, 46)
        Me.labelStatus.Name = "labelStatus"
        Me.labelStatus.Size = New System.Drawing.Size(62, 13)
        Me.labelStatus.TabIndex = 7
        Me.labelStatus.Text = "Waiting..."
        '
        'buttGen
        '
        Me.buttGen.Location = New System.Drawing.Point(9, 19)
        Me.buttGen.Name = "buttGen"
        Me.buttGen.Size = New System.Drawing.Size(62, 23)
        Me.buttGen.TabIndex = 6
        Me.buttGen.Text = "Generate"
        Me.buttGen.UseVisualStyleBackColor = True
        '
        'spinGenRate
        '
        Me.spinGenRate.Location = New System.Drawing.Point(302, 22)
        Me.spinGenRate.Maximum = New Decimal(New Integer() {192000, 0, 0, 0})
        Me.spinGenRate.Minimum = New Decimal(New Integer() {1, 0, 0, 0})
        Me.spinGenRate.Name = "spinGenRate"
        Me.spinGenRate.Size = New System.Drawing.Size(81, 20)
        Me.spinGenRate.TabIndex = 4
        Me.spinGenRate.Value = New Decimal(New Integer() {44100, 0, 0, 0})
        '
        'labelDoesAnybodyEvenReadThis
        '
        Me.labelDoesAnybodyEvenReadThis.AutoSize = True
        Me.labelDoesAnybodyEvenReadThis.Location = New System.Drawing.Point(228, 24)
        Me.labelDoesAnybodyEvenReadThis.Name = "labelDoesAnybodyEvenReadThis"
        Me.labelDoesAnybodyEvenReadThis.Size = New System.Drawing.Size(68, 13)
        Me.labelDoesAnybodyEvenReadThis.TabIndex = 5
        Me.labelDoesAnybodyEvenReadThis.Text = "SampleRate:"
        '
        'saveWAV
        '
        Me.saveWAV.DefaultExt = "wav"
        Me.saveWAV.Filter = """WAVE Files|*.wav"""
        '
        'PictureBox1
        '
        Me.PictureBox1.Image = Global.MusicString.My.Resources.Resources.logotext800px
        Me.PictureBox1.Location = New System.Drawing.Point(12, 325)
        Me.PictureBox1.Name = "PictureBox1"
        Me.PictureBox1.Size = New System.Drawing.Size(243, 105)
        Me.PictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage
        Me.PictureBox1.TabIndex = 9
        Me.PictureBox1.TabStop = False
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(261, 325)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(146, 13)
        Me.Label2.TabIndex = 10
        Me.Label2.Text = "MusicStringDLL with VB.NET"
        '
        'LinkLabel1
        '
        Me.LinkLabel1.AutoSize = True
        Me.LinkLabel1.Location = New System.Drawing.Point(261, 342)
        Me.LinkLabel1.Name = "LinkLabel1"
        Me.LinkLabel1.Size = New System.Drawing.Size(140, 13)
        Me.LinkLabel1.TabIndex = 11
        Me.LinkLabel1.TabStop = True
        Me.LinkLabel1.Text = "http://musicstring.solirax.org"
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Location = New System.Drawing.Point(261, 364)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(151, 39)
        Me.Label3.TabIndex = 12
        Me.Label3.Text = "MusicString, MusiscStringDLL," & Global.Microsoft.VisualBasic.ChrW(13) & Global.Microsoft.VisualBasic.ChrW(10) & "and this example are made by" & Global.Microsoft.VisualBasic.ChrW(13) & Global.Microsoft.VisualBasic.ChrW(10) & "Frooxius"
        '
        'LinkLabel2
        '
        Me.LinkLabel2.AutoSize = True
        Me.LinkLabel2.Location = New System.Drawing.Point(261, 410)
        Me.LinkLabel2.Name = "LinkLabel2"
        Me.LinkLabel2.Size = New System.Drawing.Size(124, 13)
        Me.LinkLabel2.TabIndex = 13
        Me.LinkLabel2.TabStop = True
        Me.LinkLabel2.Text = "http://frooxius.solirax.org"
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(416, 432)
        Me.Controls.Add(Me.LinkLabel2)
        Me.Controls.Add(Me.Label3)
        Me.Controls.Add(Me.LinkLabel1)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.PictureBox1)
        Me.Controls.Add(Me.groupGenerate)
        Me.Controls.Add(Me.groupPlayback)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.textCode)
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle
        Me.MaximizeBox = False
        Me.Name = "Form1"
        Me.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide
        Me.Text = "MusicStringDLL in VB.NET by Frooxius"
        CType(Me.spinPlayRate, System.ComponentModel.ISupportInitialize).EndInit()
        Me.groupPlayback.ResumeLayout(False)
        Me.groupPlayback.PerformLayout()
        Me.groupGenerate.ResumeLayout(False)
        Me.groupGenerate.PerformLayout()
        CType(Me.spinMaxTime, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.spinGenRate, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.PictureBox1, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents textCode As System.Windows.Forms.TextBox
    Friend WithEvents buttPlay As System.Windows.Forms.Button
    Friend WithEvents buttPause As System.Windows.Forms.Button
    Friend WithEvents buttStop As System.Windows.Forms.Button
    Friend WithEvents spinPlayRate As System.Windows.Forms.NumericUpDown
    Friend WithEvents labelPlayRate As System.Windows.Forms.Label
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents groupPlayback As System.Windows.Forms.GroupBox
    Friend WithEvents groupGenerate As System.Windows.Forms.GroupBox
    Friend WithEvents labelStatus As System.Windows.Forms.Label
    Friend WithEvents buttGen As System.Windows.Forms.Button
    Friend WithEvents spinGenRate As System.Windows.Forms.NumericUpDown
    Friend WithEvents labelDoesAnybodyEvenReadThis As System.Windows.Forms.Label
    Friend WithEvents saveWAV As System.Windows.Forms.SaveFileDialog
    Friend WithEvents spinMaxTime As System.Windows.Forms.NumericUpDown
    Friend WithEvents labelSeconds As System.Windows.Forms.Label
    Friend WithEvents PictureBox1 As System.Windows.Forms.PictureBox
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents LinkLabel1 As System.Windows.Forms.LinkLabel
    Friend WithEvents Label3 As System.Windows.Forms.Label
    Friend WithEvents LinkLabel2 As System.Windows.Forms.LinkLabel

End Class
