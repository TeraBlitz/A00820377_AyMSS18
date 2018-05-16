import { Component, OnInit } from '@angular/core';
import { ActivatedRoute, Router } from '@angular/router';
import { MateriasPrimasService } from '../../../services/materias-primas.service';
import { MatSnackBar } from '@angular/material';

@Component({
  selector: 'app-materias-primas-edit',
  templateUrl: './materias-primas-edit.component.html',
  styleUrls: ['./materias-primas-edit.component.scss']
})
export class MateriasPrimasEditComponent implements OnInit {
  public id: any;
  public mp: any;

  constructor(
    private route: ActivatedRoute,
    private router: Router,
    private mpService: MateriasPrimasService,
    private snackBar: MatSnackBar
  ) {
    this.mp = {};
  }

  ngOnInit() {
    this.id = this.route.snapshot.params['id'];
    if (this.id) {
      this.mpService.getMp(this.id).subscribe((response: any) => {
        this.mp = response.item;
      });
    }
  }

  createMp() {
    this.mpService
      .createMp(this.mp)
      .catch((error, caught) => {
        this.snackBar.open(
          'La materia prima no pudo ser agregada. Verificar los datos.',
          null,
          {
            duration: 2000
          }
        );
        return caught;
      })
      .subscribe(() => {
        this.router.navigateByUrl('/admin/materias-primas/list');
      });
  }

  updateMp() {
    this.mpService
      .updateMp(this.mp)
      .catch((error, caught) => {
        this.snackBar.open(
          'La materia prima no pudo ser modificada. Verificar los datos.',
          null,
          {
            duration: 2000
          }
        );
        return caught;
      })
      .subscribe(() => {
        this.router.navigateByUrl('/admin/materias-primas/list');
      });
  }
}
