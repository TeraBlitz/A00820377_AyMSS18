import { Component, OnInit } from '@angular/core';
import { Router } from '@angular/router';
import { AdminService } from '../../../services/admin.service';
import { MatSnackBar } from '@angular/material';

@Component({
  selector: 'app-login',
  templateUrl: './login.component.html',
  styleUrls: ['./login.component.scss']
})
export class LoginComponent implements OnInit {
  public username: string;
  public password: string;

  constructor(
    private router: Router,
    private adminService: AdminService,
    private snackBar: MatSnackBar
  ) {}

  ngOnInit() {}

  login() {
    this.adminService
      .login({ username: this.username, password: this.password })
      .subscribe((response: any) => {
        if (response.success) {
          this.router.navigateByUrl('/admin/materias-primas/list');
        } else {
          this.snackBar.open('Datos inválidos', null, {
            duration: 2000
          });
        }
      });
  }
}
